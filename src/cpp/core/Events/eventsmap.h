#pragma once
#include <unordered_map>
#include <QEvent>

class EventsMap {
    public: 
    static std::unordered_map<std::string, int> events;
};