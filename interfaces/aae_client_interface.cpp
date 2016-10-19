#include "aae_client_interface.h"



AAE_Client_Interface::AAE_Client_Interface(QObject *parent) : QObject(parent)
{


}


AAE_Client_Interface::~AAE_Client_Interface()
{

    if (m_socket)
        delete m_socket;

}


void AAE_Client_Interface::SetSocketInterface(qintptr socketDescriptor)
{

    if (!socketDescriptor)
        return;


    m_socketDescriptor = socketDescriptor;
    m_socket = new QTcpSocket(this);
    if (!m_socket)
        return;


    connect(m_socket, &QTcpSocket::disconnected, this, &AAE_Client_Interface::on_disconnected);
    connect(m_socket, &QTcpSocket::readyRead, this, &AAE_Client_Interface::on_ready_read);


    if (!m_socket->setSocketDescriptor(m_socketDescriptor))
        qDebug() << "Could not match socket" << m_socketDescriptor << "with interface!";
    else
        qDebug() << m_socketDescriptor << "connected!";

}



void AAE_Client_Interface::on_ready_read()
{

    aae_pipe::Message msg_to_send;
    msg_to_send.set_msg("This is a test message!");
    msg_to_send.set_code(42);


    int msg_size = msg_to_send.ByteSize();
    void * mem_buffer = malloc(msg_size);
    msg_to_send.SerializeToArray(mem_buffer, msg_size);
    m_socket->write(QByteArray::fromRawData((const char*)mem_buffer, msg_size));
    free(mem_buffer);

}




void AAE_Client_Interface::on_disconnected()
{

    qDebug() << m_socketDescriptor << "disconnected!";
    emit has_diconnected();

}
