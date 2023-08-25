#include<iostream>
#include <string>
#include <vector>
using namespace std;

class Door {
public:
	virtual void open(){}
	virtual void close(){}
};

class IDoorsStateNotifier{
    public :
    virtual void notify(string status) = 0;

};

class SecuredDoor : public Door{

    IDoorsStateNotifier* notifierRef;

    public: 
    SecuredDoor(IDoorsStateNotifier* notifierRefArg) : notifierRef{notifierRefArg}{}
    void open() override {
        this->notifierRef->notify("open");
    }
    void close() override {
        this->notifierRef->notify("closed");
    }
};

class Buzzer : public IDoorsStateNotifier{

public:
	void makeNoise(){}
    void notify(string status){
        cout << "Buzzer Notified ! Door status is -> " << status << endl;
        this->makeNoise();
    }
};

class  SMSManager: public IDoorsStateNotifier{

	public :void sendNotificationMessage() {

	 }
    void notify(string status){
        cout << "SMS Manager Notified ! Door status is -> " << status << endl;        
        this->sendNotificationMessage();
    }
};

class VisualizationManager : public IDoorsStateNotifier{
	public:void turnVideoOn() {}
	public:void turnVideoOff() {}

    void notify(string status){
          cout << "Visual Manager Notified ! Door status is -> " << status << endl;      
    }
};


class CompositeNotifyManager : public IDoorsStateNotifier {

    private :
    vector<IDoorsStateNotifier*> notifiers;

    public :
    void addNotifier(IDoorsStateNotifier* notifier){
        notifiers.push_back(notifier);
    }
    
    void notify(string status){

        //multicast
        for(auto notifier : notifiers){
            notifier->notify(status);
        }
    }
};

int main(){

    //Door obj;
    SMSManager smsMgrObj;
    CompositeNotifyManager cm;
    Buzzer buzzerObj;
    cm.addNotifier(&buzzerObj);
    cm.addNotifier(&smsMgrObj);
    SecuredDoor newDoor(&cm);
    newDoor.open();
    newDoor.close();
   // SecuredDoor sd1{&buzzerObj};
   // sd1.open();
    // sd1.close();


}