class Twitter {
public:
    // for storing followee of the user
    unordered_map<int,unordered_set<int>>friends;

    // for storing time at which user Posts and tweetId as well
    unordered_map<int,vector<pair<int,int>>>tweets;

    // initial time and it increses when someone post tweet
    int time = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        // simply push into account of user about the time and tweetId

        tweets[userId].push_back({++time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {

        /* Main task is here

        In the max heap I am inserting {time,userId,index,tweetId}
        initially push all the friends recent tweeets in the priority
        queue, their id , index as well as tweetId. Time will be first
        so that heap will work based on time
        make sure you also does the same for the user 
        now everything same as merging K sorted arrays
        */ 

        priority_queue<vector<int>>pq;
        vector<int>ans;
        for(auto &it : friends[userId]){
            if(tweets[it].size()){
                auto [t,tId] = tweets[it].back();
                pq.push({t,it,(int)tweets[it].size()-1,tId});
            }
        }
        if(tweets[userId].size()){
            auto [t,tId] = tweets[userId].back();
            pq.push({t,userId,(int)tweets[userId].size()-1,tId});
        }


        /*
        In the while loop push topTweet to the answer and add   
        corresponding userId's previous tweet into the priority queue 
        if user has previous tweets then only.
        make sure you done this all things only for 10 times
        */

        int k = 10;
        while(k>0 && !pq.empty()){
            vector<int>v = pq.top();
            pq.pop();
            ans.push_back(v[3]);
            if(v[2]!=0){
                auto [newTime, newTweetId] = tweets[v[1]][v[2]-1];
                pq.push({newTime,v[1],v[2]-1,newTweetId});
            }
            k--;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        // insert the followeeId in the followerId

        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {

        // if followerId follow the followeeId then remove

        if(friends[followerId].find(followeeId)!=friends[followerId].end())
            friends[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */