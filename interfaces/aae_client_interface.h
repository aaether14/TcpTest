#ifndef AAE_CLIENT_INTERFACE_H
#define AAE_CLIENT_INTERFACE_H


#include <QTcpSocket>
#include "protoc/pipe.pb.h"


class AAE_Client_Interface : public QObject
{

    Q_OBJECT
    /**
     * @brief m_socket is the QT socket interface
     */
    QTcpSocket * m_socket;
    /**
     * @brief m_socketDescriptor is the os id of the socket endpoint
     */
    qintptr m_socketDescriptor;

public:

    /**
     * @brief AAE_Client_Interface is a basic QObject constructor
     * @param parent is the parent of the QObject
     */
    explicit AAE_Client_Interface(QObject * parent);

    /**
     * @brief ~AAE_Client_Interface is the destructor of the client interface
     */
    virtual ~AAE_Client_Interface();

    /**
     * @brief SetSocketInterface will match a socket id with a QT interface
     * @param socketDescriptor is the os id of the socket endpoint
     */
    void SetSocketInterface(qintptr socketDescriptor);


signals:
    /**
     * @brief has_diconnected will be emitted on socket disconnection
     */
    void has_diconnected();

public slots:
    /**
     * @brief on_ready_read is the way to approach client-sent data
     */
    void on_ready_read();
    void on_disconnected();


};

#endif // AAE_CLIENT_INTERFACE_H
