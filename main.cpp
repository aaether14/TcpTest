#include <QCoreApplication>
#include "interfaces/aae_server_interface.h"


int main(int argc, char *argv[])
{

    GOOGLE_PROTOBUF_VERIFY_VERSION;
    QCoreApplication a(argc, argv);

    AAE_Server_Interface server_interface;
    server_interface.Start();

    google::protobuf::ShutdownProtobufLibrary();
    return a.exec();

}
