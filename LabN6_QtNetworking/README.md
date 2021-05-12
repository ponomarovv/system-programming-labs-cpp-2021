# Description
Here you have two Qt projects. One for Client side and one for Server side.

These project was running on two VirtualBox virtual machines. In order to do the same you have to configure port forwarding. You can see an example in config folder.

Then you have to open `Client/mainwindow.h` file and assign your **host** machine IP and port address to LOCAL_HOST_IP and PORT fields respectively;

Finaly, you have to open `Server/mainwindow.h` file and assign you **virtual** machine IP address and port to LOCAL_IP and PORT field respectively.

Now you are ready to use this application. Start server, connect to server from client part and have fun! ;)