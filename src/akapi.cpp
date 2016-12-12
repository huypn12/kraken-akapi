#include <akapi.h>

void kraken::akapi::process_response(web::json::value const & jvalue)
{
    if (!jvalue.is_null()) {
        for (auto const & e : jvalue) {
            std::cout << e.first.as_string() << " = " << e.second.as_string() << std::endl;
        }
    }
}

void kraken::akapi::make_request(
        web::http::client::http_client &client,
        web::http::method mtd,
        web::json::value const & jvalue
        )
{
    make_task_request(client, mtd, jvalue).then(
            [this](web::http::http_response response) {
            if (response.status_code() == web::http::status_codes::OK) {
            return response.extract_json();
            }
            return pplx::task_from_result(web::json::value());
            }).then(
                [this](pplx::task<web::json::value> previous_task) {
                try {
                const web::json::value & v = previous_task.get();
                process_response(v);
                } catch (web::http::http_exception const &e) {
                std::cerr << e.what() << std::endl;
                }
                }
                ).wait();
}



pplx::task<web::http::http_response> kraken::akapi::make_task_request(
        web::http::client::http_client &client,
        web::http::method mtd,
        web::json::value const & jvalue
        )
{
    return client.request(mtd, "/");
}


