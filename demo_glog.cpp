/*
 * @Author: songjintao
 * @Date: 2022-01-23 17:36:55
 * @Description:
 *
 */
#include <glog/logging.h>

int main(int argc, char **argv) {
    LOG(INFO) << "test log: ";

    for (int i = 0; i < 80; i++) {
        LOG_EVERY_N(INFO, 5) << "test log every n: " << google::COUNTER;

        LOG_IF(INFO, i%10 == 9) << "test log if: ";
        
        LOG_FIRST_N(INFO, 5)<<"test first n: ";

        // output
        VLOG(-1)<<"test vlog: -1";
        VLOG(0)<<"test vlog: 0";

        // not output
        VLOG(1)<<"test vlog: 1";
        VLOG(2)<<"test vlog: 2";
        VLOG(3)<<"test vlog: 3";
        
        // debug
        DLOG(INFO)<<"test dlog: ";
        DCHECK_LE(i, 35)<<"test dcheck_ge: ";  

        // Fatal, DFATAL when model is debug, DFATAL is Fatal, but DFATAL is ERROR
        LOG(DFATAL)<<"test Dfatal";
        LOG(FATAL)<<"test fatal";
        /*
            GLOG_minloglevel=2 ./demo_glog_main
            WARNING: Logging before InitGoogleLogging() is written to STDERR
            E0123 18:49:34.690111 27665 demo_glog.cpp:33] test Dfatal
            F0123 18:49:34.690127 27665 demo_glog.cpp:35] test fatal
            *** Check failure stack trace: ***
            [1]    27665 abort (core dumped)  GLOG_minloglevel=2 ./demo_glog_main
        */


        //check
        CHECK_LE(i, 55)<<"test check_ge: ";        

        //pcheck
        // PCHECK(i==45)<<"test pcheck: ";
    }

    
}