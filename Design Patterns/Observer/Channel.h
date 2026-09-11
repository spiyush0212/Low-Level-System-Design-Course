#pragma once

#include "IChannel.h"
#include <unordered_set>    
#include <string>
#include <vector>

using namespace std;

class Channel : public IChannel {
public:
    Channel(const string& name) : channelName(name) {};

    virtual ~Channel() = default;

    void notify() override {
        for (auto subscriber : subscribers) {
            subscriber->update();
        }
    }

    void subscribe(ISubscriber* subscriber) override {
        subscribers.insert(subscriber);
    }

    void unsubscribe(ISubscriber* subscriber) override {
        subscribers.erase(subscriber);
    }

    void publishVideo(const string& video) {
        videos.push_back(video);
        notify();
    }

    string getLatestVideo() const {
        if (!videos.empty()) {
            return videos.back();
        }
        return "";
    }

private:
    unordered_set<ISubscriber*> subscribers;
    string channelName;
    vector<string> videos;
};