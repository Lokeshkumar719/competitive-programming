class RideSharingSystem {
public:
  queue<int>rider,driver;
  set<int>cancelled,riderBooked;
  RideSharingSystem() {
      
  }
    
  void addRider(int riderId) {
    rider.push(riderId);
    riderBooked.insert(riderId);
  }
    
  void addDriver(int driverId) {
    driver.push(driverId);
  }
    
  vector<int> matchDriverWithRider() {
    while(rider.size() && cancelled.count(rider.front())){
      rider.pop();
    }
    if(rider.size() && driver.size()){
      vector<int>ans={driver.front(),rider.front()};
      driver.pop();
      rider.pop();
      return ans;
    }
    return {-1,-1};
  }
    
  void cancelRider(int riderId) {
    if(riderBooked.count(riderId))
      cancelled.insert(riderId);
  }
};