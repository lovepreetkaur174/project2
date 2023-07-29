#include <iostream>
#include <unordered_map>
using namespace std;

class Call
{
private:
    string uName;
    string uPhone_No;
    string uAddress;
    string ugrade;

public:
    Call()
    {
    }

    Call(string name, string phone_No, string address, string grade)
    {
        this->uName = name;
        this->uPhone_No = phone_No;
        this->uAddress = address;
        this->ugrade = grade;
    }

    void getCall()
    {
        cout << "Calling .......: " << uName << endl;
        cout << "Phone Number: " << uPhone_No << endl;
        cout << "Address: " << uAddress << endl;
        cout << "Grade: " << ugrade << endl
             << endl;
    }
};

class User : public Call
{
private:
    string name;
    string phone_No;
    string address;
    string grade;
    int duration;
    friend User changeGrade(User user, string grade);

public:
    User()
    {
    }

    User(string name, string phone_No, string address, string grade) : Call(name, phone_No, address, grade)
    {
        this->name = name;
        this->phone_No = phone_No;
        this->address = address;
        this->grade = grade;
        if(grade!=""){
            User user = changeGrade(*this, grade);
            this->duration = user.duration;
        }
    }

    void operator=(User &user)
    {
        this->name = user.name;
        this->phone_No = user.phone_No;
        this->address = user.address;
        this->grade = user.grade;
        this->duration = user.duration;
    }

    void setGradeDuration(string grade, int duration)
    {
        this->grade = grade;
        this->duration = duration;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setPhoneNo(string phone_No)
    {
        this->phone_No = phone_No;
    }

    void setAddress(string address)
    {
        this->address = address;
    }

    string getName()
    {
        return this->name;
    }

    string getPhoneNo()
    {
        return this->phone_No;
    }

    string getAddress()
    {
        return this->address;
    }

    string getGrade()
    {
        return this->grade;
    }

    int getDuration()
    {
        return this->duration;
    }

    bool operator==(User user1)
    {
        if (this->name == user1.name && this->phone_No == user1.phone_No && this->address == user1.address)
            return true;
        else
            return false;
    }

    virtual void setParameters()
    {
        cout << "Please enter the valid grade" << endl;
    }
};

class Intermediate : public User
{
private:
    int duration;

public:
    void setParameters()
    {
        setGradeDuration("Intermidate", 2);
    }
};

class Btech : public User
{
private:
    int duration;

public:
    void setParameters()
    {
        setGradeDuration("Btech", 4);
    }
};

class Mtech : public User
{
private:
    int duration;

public:
    void setParameters()
    {
        setGradeDuration("Mtech", 2);
    }
};

class Phd : public User
{
private:
    int duration;

public:
    void setParameters()
    {
        setGradeDuration("Phd", 5);
    }
};

class Phone_Book
{
private:
    unordered_map<string, User> userDetails;

public:
    Phone_Book(){

    };

    friend User changeGrade(User user, string grade);

    // Add the user to the map
    Phone_Book &operator+=(User user1)
    {
        if (userDetails.find(user1.getPhoneNo()) != userDetails.end())
        {
            cout << "Duplicates numbers are not allowed" << endl
                 << endl
                 << endl;
        }
        else
        {
            string phoneno = user1.getPhoneNo();
            userDetails[phoneno] = user1;
            cout << "User Details has been successfully added to Phone Book" << endl
                 << endl;
        }
        return *this;
    }

    // search based on name and number
    void search(User user)
    {
        if (userDetails.find(user.getPhoneNo()) == userDetails.end())
        {
            cout << "User does not found" << endl
                 << endl;
        }
        else
        {
            User user1 = userDetails[user.getPhoneNo()];
            cout << "Name of the user: " << user1.getName() << endl;
            cout << "Phone of the user: " << user1.getPhoneNo() << endl;
            cout << "Address of the user: " << user1.getAddress() << endl;
            cout << "Grade of the user: " << user1.getGrade() << endl;
            cout << "Duration of the user: " << user1.getDuration() << endl
                 << endl;
        }
    }

    // change the details of the user
    void change(User user)
    {
        if (userDetails.find(user.getPhoneNo()) == userDetails.end())
        {
            cout << "User does not found" << endl
                 << endl;
        }
        else
        {
            User user1 = userDetails[user.getPhoneNo()];
            string uName;
            string uPhone_No;
            string uAddress;
            string phoneNo;
            int choice;
            cout << "Press 1 to change the Name: " << endl;
            cout << "Press 2 to change the Phone Number: " << endl;
            cout << "Press 3 to change the Address: " << endl;
            cout << "Press 4 to change the Grade: " << endl;
            cout<<"Choice "<<endl;
            cin >> choice;
            cout<<endl;

            phoneNo = user1.getPhoneNo();

            switch (choice)
            {
            case 1:
            {
                cout << "Enter the Updated Name: ";
                getline(cin,uName);
                fflush(stdin);
                user1.setName(uName);
                break;
            }
            case 2:
            {
                cout << "Enter the Updated Phone Number: ";
                getline(cin,uPhone_No);
                fflush(stdin);
                phoneNo = uPhone_No;
                user1.setPhoneNo(uPhone_No);
                break;
            }
            case 3:
            {
                cout << "Enter the Updated Address: ";
                getline(cin,uAddress);
                fflush(stdin);
                user1.setAddress(uAddress);
                break;
            }
            case 4:
            {
                cout << "Press 1 to change the grade to Intermediate" << endl;
                cout << "Press 2 to change the grade to Btech" << endl;
                cout << "Press 3 to change the grade to Mtech" << endl;
                cout << "Press 4 to change the grade to Phd" << endl
                     << endl;
                int gr;
                cin >> gr;
                
                switch (gr)
                {
                case 1:{
                    User user2 = changeGrade(user1, "Intermediate");
                    user1 =user2;
                    break;
                }
                case 2:{
                    User user2 =  changeGrade(user1, "Btech");
                    user1 =user2;
                    break;
                }
                case 3:{
                    User user2 = changeGrade(user1, "Mtech");
                    user1 =user2;
                    break;
                }
                case 4:{
                    User user2 = changeGrade(user1, "Phd");
                    user1 =user2;
                    break;
                }
                default:{
                    cout << "Enter the correct choice" << endl
                         << endl;
                    break;
                    }
                }
            userDetails[phoneNo] = user1;
            default:
                cout << "Enter the correct choice from the given choice" << endl
                     << endl;
                break;
            }
            }

            userDetails[phoneNo] = user1;
        }
    }
    // delete the user from the map
    void operator-=(User user1)
    {
        if (userDetails.find(user1.getPhoneNo()) == userDetails.end())
        {
            cout << "User does not found" << endl
                 << endl;
        }
        else
        {
            userDetails.erase(user1.getPhoneNo());
            cout << "User Details has been deleted successfully" << endl
                 << endl;
        }
    }

    void callTheUser(User user)
    {
        if (userDetails.find(user.getPhoneNo()) == userDetails.end())
        {
            cout << "Enter the correct Phone Number of the user as it is not present in the Phone Book" << endl
                 << endl;
        }
        User user1 = userDetails[user.getPhoneNo()];
        User user2(user1.getName(), user1.getPhoneNo(), user1.getAddress(), user1.getGrade());
        user2.getCall();
    }
};

// change the grade of the user or add the grade
User changeGrade(User user, string grade)
{
    User *u;
    Intermediate inter;
    Mtech mt;
    Btech bt;
    Phd phd;
    
    if (grade == "Intermediate")
    {
        u = &inter;
    }
    else if (grade == "Btech")
    {
        u = &bt;
    }
    else if (grade == "Mtech")
    {
        u = &mt;
    }
    else if (grade == "Phd")
    {
        u = &phd;
    }
    else
    {       
        cout << "Enter the correct grade" << endl;
        return user;
    }
    u->setParameters();
    user.grade = u->grade;
    user.duration = u->duration;
    return user;
}

int main()
{
    Phone_Book phone_book;
    int choice = -1;
    while (choice != 6)
    {
        cout << "Please enter 1 for creating new User" << endl;
        cout << "Please enter 2 for Changing User Details" << endl;
        cout << "Please enter 3 for Searching the User" << endl;
        cout << "Please enter 4 for Deleting the User" << endl;
        cout << "Please enter 5 for Calling the User" << endl;
        cout << "Please enter 6 for Closing the Phone Book" << endl
             << endl;
        cout << "Choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
        {
            string name;
            string phone_No;
            string address;
            string grade;

            cout << "Enter Your Details" << endl;
            cout << "Enter the Name: ";
            fflush(stdin);
            getline(cin, name);
            fflush(stdin);
            cout << "Enter the Phone Number: ";
            getline(cin, phone_No);
            fflush(stdin);
            cout << "Enter the Address: ";
            getline(cin, address);
            fflush(stdin);
            cout << "Enter the Grade: ";
            getline(cin, grade);
            fflush(stdin);
            cout << endl
                 << endl;
            User user(name, phone_No, address, grade);
            phone_book += user;
            break;
        }
        case 2:
        {
            string phonenumber;
            cout << "Enter the Phone Number of the user for changing the details: ";
            fflush(stdin);
            getline(cin, phonenumber);
            fflush(stdin);
            cout << endl
                 << endl;
            User user("", phonenumber, "", "");
            phone_book.change(user);
            break;
        }
        case 3:
        {
            string phonenumber;
            cout << "Enter the Phone Number of the user for searching the user: ";
            fflush(stdin);
            getline(cin, phonenumber);
            fflush(stdin);
            cout << endl
                 << endl;
            User user("", phonenumber, "", "");
            phone_book.search(user);
            break;
        }
        case 4:
        {
            string phonenumber;
            cout << "Enter the Phone Number of the user for deleting the userdetails: ";
            fflush(stdin);
            getline(cin, phonenumber);
            fflush(stdin);
            cout << endl
                 << endl;
            User user("", phonenumber, "", "");
            phone_book -= user;
            break;
        }
        case 5:
        {
            string phonenumber;
            cout << "Enter the Phone Number of the user for calling the user: ";
            fflush(stdin);
            getline(cin, phonenumber);
            fflush(stdin);
            cout << endl
                 << endl;
            User user("", phonenumber, "", "");
            phone_book.callTheUser(user);
            break;
        }
        case 6:
        {
            cout << "Phone Book has been close" << endl;
            break;
        }
        default:
        {
            cout << "Enter the correct choices from the above details" << endl;
            break;
        }
        }
    }
    return 0;
}