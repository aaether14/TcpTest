#ifndef AAE_SERVER_H
#define AAE_SERVER_H


#include <QTcpServer>
#include <QThreadPool>
#include "aae_client_interface.h"


class AAE_Server_Interface : public QTcpServer
{


    Q_OBJECT

    /**
     * @brief m_port is the port we're connecting to
     */
    const quint16 m_port = 8080;
    /**
     * @brief m_adress is the adress we're connecting to
     */
    const QHostAddress m_adress = QHostAddress("192.168.1.20");


public:

    /**
     * @brief AAE_Server is the default constructor of the server interface
     * @param parent is the parent of the QObject
     */
    explicit AAE_Server_Interface(QObject *parent = 0);


    /**
     * @brief Start will start the server :P
     */
    void Start();


protected:
    /**
     * @brief incomingConnection will handle an incoming connection
     * @param socketDescriptor is the os id of the socket
     */
     void incomingConnection(qintptr socketDescriptor);

};

#endif // AAE_SERVER_H
