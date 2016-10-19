#include "aae_server_interface.h"



AAE_Server_Interface::AAE_Server_Interface(QObject *parent) : QTcpServer(parent)
{

    QThreadPool::globalInstance()->setMaxThreadCount(4);

}


void AAE_Server_Interface::Start()
{


    if (!listen(m_adress, m_port))
        qDebug() << "Server cound not start! -" << errorString();
    else
        qDebug() << "Server has started!";


}


void AAE_Server_Interface::incomingConnection(qintptr socketDescriptor)
{

    AAE_Client_Interface * client_interface = new AAE_Client_Interface(this);
    connect(client_interface, &AAE_Client_Interface::has_diconnected, client_interface, &QObject::deleteLater);
    client_interface->SetSocketInterface(socketDescriptor);

}
