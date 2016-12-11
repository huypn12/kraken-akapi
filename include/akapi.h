#ifndef __AKAPI__
#define __AKAPI__


#include <cpprest/http_client.h>
#include <cpprest/json.h>


namespace kraken {
    class akapi {
        public:
            void make_request(
                    web::http::client::http_client &,
                    web::http::method mtd,
                    web::json::value const &
                    );


        private:
            pplx::task<web::http::http_response> make_task_request(
                    web::http::client::http_client &,
                    web::http::method mtd,
                    web::json::value const &
                    );

            void process_response(web::json::value const &);
    };

};


#endif
