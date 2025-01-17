class ParkingSystem {
public:
    int x,y,z;
    ParkingSystem(int big, int medium, int small) {
         x=big;
        y=medium;
        z=small;
    }
    
    bool addCar(int carType) {
        if(carType==1 && x>0){
            x--;
            return true;
        }
        else if(carType==2 && y>0){
            y--;
            return true;
        }
        else if(carType==3 && z>0){
            z--;
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */