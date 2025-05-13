#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H

#include <thread>
#include <atomic>


struct Coordinates
{
    float x;
    float y;
};

enum class NetworkRole
{
    NONE,
    SERVER,
    CLIENT
};

class NetworkManager
{
private:
    void RunServer();
    void RunClient();

    std::thread serverThread;
    std::atomic<bool> running;
    NetworkRole role;

    Coordinates ownPosition = {0, 0};
    Coordinates otherPosition = {0, 0};

public:
    NetworkManager(NetworkRole _role);
    ~NetworkManager();

    void Start();
    void Stop();

    void SetOwnPosition(const Coordinates &_position);
    Coordinates GetOtherPosition() const;
};

#endif // NETWORK_MANAGER_H