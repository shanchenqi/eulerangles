#include <opencv2/core.hpp>
#include <opencv2/core/quaternion.hpp>
#include <iostream>
using namespace std;
using namespace cv;

enum EulerAnglesOrder{
    INT_XYZ,
    INT_XZY,
    INT_YXZ,
    INT_YZX,
    INT_ZXY,
    INT_ZYX,

    INT_YXY,
    INT_ZXZ,
    INT_XYX,
    INT_ZYZ,
    INT_YZY,
    INT_XZX,

    EXT_XYZ,
    EXT_XZY,
    EXT_YXZ,
    EXT_YZX,
    EXT_ZXY,
    EXT_ZYX,

    EXT_YXY,
    EXT_ZXZ,
    EXT_XYX,
    EXT_ZYZ,
    EXT_XZX,
    EXT_YZY,

};
template <typename T>
Quat<T> getHeading(T m){
    Quat<T> H = { std::cos(m), 0, std::sin(m), 0};
    return H;
}

template <typename T>
Quat<T> getPitch(T m){
    Quat<T> P = { std::cos(m), std::sin(m), 0, 0};
    return P;
}

template <typename T>
Quat<T> getBank(T m){
    Quat<T> B = { std::cos(m), 0, 0, std::sin(m)};
    return B;
}


template <typename T>
Quat<T> EularToAngles(const Vec<T, 3> &rad,EulerAnglesOrder order){
    Quat<T> qEluar;
    switch (order)
    {
    case INT_XYZ:
    {
        Quat<T> H = getHeading(rad(1)/2);
        Quat<T> P = getPitch(rad(0)/2);
        Quat<T> B = getBank(rad(2)/2);
        qEluar = P * H * B;
        break;
    }
    case INT_XZY:
    {
        Quat<T> H = getHeading(rad(2) / 2);
        Quat<T> P = getPitch(rad(0) / 2);
        Quat<T> B = getBank(rad(1) / 2);
        qEluar = P * B * H;
        break;
    }
    case INT_YXZ:
    {
        Quat<T> H = getHeading(rad(0) / 2);
        Quat<T> P = getPitch(rad(1) / 2);
        Quat<T> B = getBank(rad(2) / 2);
        qEluar = H * P * B;
        break;
    }
    case INT_YZX:
    {
        Quat<T> H = getHeading(rad(0) / 2);
        Quat<T> P = getPitch(rad(2) / 2);
        Quat<T> B = getBank(rad(1) / 2);
        qEluar = H * B * P;
        break;
    }
    case INT_ZXY:
    {
        Quat<T> H = getHeading(rad(2) / 2);
        Quat<T> P = getPitch(rad(1) / 2);
        Quat<T> B = getBank(rad(0) / 2);
        qEluar = B * P * H;
        break;
    }
    case INT_ZYX:
    {
        Quat<T> H = getHeading(rad(1) / 2);
        Quat<T> P = getPitch(rad(2) / 2);
        Quat<T> B = getBank(rad(0) / 2);
        qEluar = B * H * P;
        break;
    }

    case EXT_XYZ:
    {
        Quat<T> H = getHeading(rad(1)/2);
        Quat<T> P = getPitch(rad(0)/2);
        Quat<T> B = getBank(rad(2)/2);
        qEluar = B * H * P;
        break;
    }
    case EXT_XZY:
    {
        Quat<T> H = getHeading(rad(2) / 2);
        Quat<T> P = getPitch(rad(0) / 2);
        Quat<T> B = getBank(rad(1) / 2);
        qEluar = H * B * P;
        break;
    }
    case EXT_YXZ:
    {
        Quat<T> H = getHeading(rad(0) / 2);
        Quat<T> P = getPitch(rad(1) / 2);
        Quat<T> B = getBank(rad(2) / 2);
        qEluar = B * P * H;
        break;
    }
    case EXT_YZX:
    {
        Quat<T> H = getHeading(rad(0) / 2);
        Quat<T> P = getPitch(rad(2) / 2);
        Quat<T> B = getBank(rad(1) / 2);
        qEluar = P * B * H;
        break;
    }
    case EXT_ZXY:
    {
        Quat<T> H = getHeading(rad(2) / 2);
        Quat<T> P = getPitch(rad(1) / 2);
        Quat<T> B = getBank(rad(0) / 2);
        qEluar = H * P * B;
        break;
    }
    case EXT_ZYX:
    {
        Quat<T> H = getHeading(rad(1) / 2);
        Quat<T> P = getPitch(rad(2) / 2);
        Quat<T> B = getBank(rad(0) / 2);
        qEluar = P * H * B;
        break;
    }


    case INT_YXY:
    {
        Quat<T> H1 = getHeading(rad(0) / 2);
        Quat<T> P = getPitch(rad(1) / 2);
        Quat<T> H2 = getHeading(rad(2) / 2);
        qEluar = H1 * P * H2;
        break;
    }
    case EXT_YXY:
    {
        Quat<T> H1 = getHeading(rad(0) / 2);
        Quat<T> P = getPitch(rad(1) / 2);
        Quat<T> H2 = getHeading(rad(2) / 2);
        qEluar = H2 * P * H1;
        break;
    }


    case INT_ZXZ:
    {
        Quat<T> B1 = getBank(rad(0) / 2);
        Quat<T> P = getPitch(rad(1) / 2);
        Quat<T> B2 = getBank(rad(2) / 2);
        qEluar = B1 * P * B2;
        break;
    }
    case EXT_ZXZ:
    {
        Quat<T> B1 = getBank(rad(0) / 2);
        Quat<T> P = getPitch(rad(1) / 2);
        Quat<T> B2 = getBank(rad(2) / 2);
        qEluar = B2 * P * B1;
        break;
    }
    case INT_XYX:
    {
        Quat<T> P1 = getPitch(rad(0) / 2);
        Quat<T> H = getHeading(rad(1) / 2);
        Quat<T> P2 = getPitch(rad(2) / 2);
        qEluar = P1 * H * P2;
        break;
    }
    case EXT_XYX:
    {
        Quat<T> P1 = getPitch(rad(0) / 2);
        Quat<T> H = getHeading(rad(1) / 2);
        Quat<T> P2 = getPitch(rad(2) / 2);
        qEluar = P2 * H * P1;
        break;
    }
    case INT_ZYZ:
    {
        Quat<T> B1 = getBank(rad(0) / 2);
        Quat<T> H = getHeading(rad(1) / 2);
        Quat<T> B2 = getBank(rad(2) / 2);
        qEluar = B1 * H * B2;
        break;
    }
    case EXT_ZYZ:
    {
        Quat<T> B1 = getBank(rad(0) / 2);
        Quat<T> H = getHeading(rad(1) / 2);
        Quat<T> B2 = getBank(rad(2) / 2);
        qEluar = B2 * H * B1;
        break;
    }
    case INT_YZY:
    {
        Quat<T> H1 = getHeading(rad(0) / 2);
        Quat<T> B = getBank(rad(1) / 2);
        Quat<T> H2 = getHeading(rad(2) / 2);
        qEluar = H1 * B * H2;
        break;
    }
    case EXT_YZY:
    {
        Quat<T> H1 = getHeading(rad(0) / 2);
        Quat<T> B = getBank(rad(1) / 2);
        Quat<T> H2 = getHeading(rad(2) / 2);
        qEluar = H2 * B * H1;
        break;
    }
    case INT_XZX:
    {
        Quat<T> P1 = getPitch(rad(0) / 2);
        Quat<T> B = getBank(rad(1) / 2);
        Quat<T> P2 = getPitch(rad(2) / 2);
        qEluar = P1 * B * P2;
        break;
    }
    case EXT_XZX:
    {
        Quat<T> P1 = getPitch(rad(0) / 2);
        Quat<T> B = getBank(rad(1) / 2);
        Quat<T> P2 = getPitch(rad(2) / 2);

        qEluar = P2 * B * P1;
        break;
    }
    default:
        qEluar = {0, 0, 0, 0};
        break;
    }

    return qEluar;
}

template <typename T>
Vec<T, 3> AnglesToEular(const Quat<T> &quat, EulerAnglesOrder order){
    Vec<T, 3> Angles;
    T w = quat.w;//r
    T x = quat.x;//i
    T y = quat.y;//j
    T z = quat.z;//k

    static const double convertMatrix[3][3] ={
        1 - 2 * y * y - 2 * z * z,2 * x * y - 2 * w * z,2 * x * z + 2 * w * y,
        2 * x * y + 2 * w * z,1 - 2 * x * x - 2 * z * z,2 * y * z - 2 * w * x,
        2 * x * z - 2 * w * y,2 * y * z + 2 * w * x,1 - 2 * x * x - 2 * y * y
    };
    switch (order)
    {

    case INT_XYZ:
    {
        if(convertMatrix[0][2]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles = {std::atan2(convertMatrix[1][0], convertMatrix[1][1]), CV_PI / 2, 0};
            break;
        }
        else if(convertMatrix[0][2]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles = {std::atan2(convertMatrix[2][1], convertMatrix[1][1]), -CV_PI / 2, 0};
            break;
        }
        Angles(0) = std::atan2(-convertMatrix[1][2], convertMatrix[2][2]);
        Angles(1) = std::atan2(convertMatrix[0][2],std::sqrt(1-convertMatrix[0][2]*convertMatrix[0][2]));
        Angles(2) = std::atan2(-convertMatrix[0][1],convertMatrix[0][0]);
        break;
    }
    case INT_XZY:
    {
         if(convertMatrix[0][1]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles = {std::atan2(-convertMatrix[1][2],convertMatrix[2][2]), -CV_PI/2, 0};
            break;
        }
        else if(convertMatrix[0][1]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles = {std::atan2(convertMatrix[2][0], convertMatrix[2][2]), CV_PI / 2, 0};
            break;
        }
        Angles(0) = std::atan2(convertMatrix[2][1],convertMatrix[1][1]);
        Angles(1) = std::atan2(-convertMatrix[0][1],std::sqrt(1-convertMatrix[0][1]*convertMatrix[0][1]));
        Angles(2) = std::atan2(convertMatrix[0][2],convertMatrix[0][0]);

        break;
    }
    case INT_XYX:
    {
        if(convertMatrix[0][0]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles = {std::atan2(convertMatrix[2][1],convertMatrix[2][2]),0,0};
            break;
        }
        else if(convertMatrix[0][0]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles = {std::atan2(convertMatrix[1][2],convertMatrix[1][1]),CV_PI,0};
            break;
        }
        Angles(0) = std::atan2(convertMatrix[1][0],-convertMatrix[2][0]);
        Angles(1) = std::atan2(std::sqrt(1-convertMatrix[0][0]*convertMatrix[0][0]),convertMatrix[0][0]);
        Angles(2) = std::atan2(convertMatrix[0][1],convertMatrix[0][2]);

        break;
    }
    case INT_XZX:
    {
        if(convertMatrix[0][0]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles = {std::atan2(convertMatrix[2][1],convertMatrix[2][2]),0,0};
            break;
        }
        else if(convertMatrix[0][0]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles = {std::atan2(-convertMatrix[2][1],convertMatrix[2][2]), CV_PI, 0};

            break;
        }
        Angles(0) = std::atan2(convertMatrix[2][0],convertMatrix[1][0]);
        Angles(1) = std::atan2(std::sqrt(1-convertMatrix[0][0]*convertMatrix[0][0]),convertMatrix[0][0]);
        Angles(2) = std::atan2(convertMatrix[0][2],-convertMatrix[0][1]);

        break;
    }
    case INT_YXZ:
    {
        if(convertMatrix[1][2]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles = {std::atan2(-convertMatrix[0][1],convertMatrix[0][0]),-CV_PI/2,0};
            break;
        }
        else if(convertMatrix[1][2]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles = {std::atan2(-convertMatrix[0][1],convertMatrix[0][0]),CV_PI/2,0};
            break;
        }
        Angles(0) = std::atan2(convertMatrix[0][2],convertMatrix[2][2]);
        Angles(1) = std::atan2(-convertMatrix[1][2],std::sqrt(1-convertMatrix[1][2]*convertMatrix[1][2]));
        Angles(2) = std::atan2(convertMatrix[1][0],convertMatrix[1][1]);
        break;
    }
    case INT_YZX:
    {
        if(convertMatrix[1][0]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles = {std::atan2(-convertMatrix[0][2],convertMatrix[0][0],CV_PI/2,0);
            break;
        }
        else if(convertMatrix[1][0]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(0) = std::atan2(-convertMatrix[0][2],convertMatrix[0][1]);
            Angles(1) = -CV_PI/2;
            Angles(2) = 0;
            break;
        }
        Angles(0) = std::atan2(-convertMatrix[2][0],convertMatrix[0][0]);
        Angles(1) = std::atan2(convertMatrix[1][0],std::sqrt(1-convertMatrix[1][0]*convertMatrix[1][0]));
        Angles(2) = std::atan2(-convertMatrix[1][2],convertMatrix[1][1]);
        break;
    }
    case INT_YXY:
    {
         if(convertMatrix[1][1]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(0) = std::atan2(convertMatrix[0][2],convertMatrix[0][0]);
            Angles(1) = 0;
            Angles(2) = 0;
            break;
        }
        else if(convertMatrix[1][1]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(0) = std::atan2(-convertMatrix[2][0],convertMatrix[0][0]);
            Angles(1) = CV_PI;
            Angles(2) = 0;
            break;
        }
        Angles(0) = std::atan2(convertMatrix[0][1],convertMatrix[2][1]);
        Angles(1) = std::atan2(std::sqrt(1-convertMatrix[1][1]*convertMatrix[1][1]),convertMatrix[1][1]);
        Angles(2) = std::atan2(convertMatrix[1][0],-convertMatrix[1][2]);
        break;
    }
    case INT_YZY:
    {
        if(convertMatrix[1][1]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(0) = std::atan2(convertMatrix[0][2],convertMatrix[0][0]);
            Angles(1) = 0;
            Angles(2) = 0;
            break;
        }
        else if(convertMatrix[1][1]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(0) = std::atan2(convertMatrix[0][2],convertMatrix[0][0]);
            Angles(1) = CV_PI;
            Angles(2) = 0;
            break;
        }
        Angles(0) = std::atan2(convertMatrix[2][1],-convertMatrix[0][1]);
        Angles(1) = std::atan2(std::sqrt(1-convertMatrix[1][1]*convertMatrix[1][1]),convertMatrix[1][1]);
        Angles(2) = std::atan2(convertMatrix[1][2],convertMatrix[1][0]);
        break;
    }
    case INT_ZXY:
    {
        if(convertMatrix[2][1]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(0) = std::atan2(convertMatrix[1][0],convertMatrix[0][0]);
            Angles(1) = CV_PI/2;
            Angles(2) = 0;
            break;
        }
        else if(convertMatrix[2][1]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(0) = std::atan2(convertMatrix[1][0],convertMatrix[0][0]);
            Angles(1) = -CV_PI/2;
            Angles(2) = 0;
            break;
        }
        Angles(0) = std::atan2(-convertMatrix[0][1],convertMatrix[1][1]);
        Angles(1) = std::atan2(convertMatrix[2][1],std::sqrt(1-convertMatrix[2][1]*convertMatrix[2][1]));
        Angles(2) = std::atan2(-convertMatrix[2][0],convertMatrix[2][2]);
        break;
    }
    case INT_ZYX:
    {
         if(convertMatrix[2][0]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(0) = std::atan2(-convertMatrix[0][1],convertMatrix[1][1]);
            Angles(1) = -CV_PI/2;
            Angles(2) = 0;
            break;
        }
        else if(convertMatrix[2][0]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(0) = std::atan2(convertMatrix[1][2],convertMatrix[1][1]);
            Angles(1) = CV_PI/2;
            Angles(2) = 0;
            break;
        }
        Angles(0) = std::atan2(convertMatrix[1][0],convertMatrix[0][0]);
        Angles(1) = std::atan2(-convertMatrix[2][0],std::sqrt(1-convertMatrix[2][0]*convertMatrix[2][0]));
        Angles(2) = std::atan2(convertMatrix[2][1],convertMatrix[2][2]);
        break;
    }
    case INT_ZXZ:
    {
        if(convertMatrix[2][2]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(0) = std::atan2(convertMatrix[1][0],convertMatrix[1][1]);
            Angles(1) = 0;
            Angles(2) = 0;
            break;
        }
        else if(convertMatrix[2][2]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(0) = std::atan2(-convertMatrix[1][0],convertMatrix[0][0]);
            Angles(1) = CV_PI;
            Angles(2) = 0;
            break;
        }
        Angles(0) = std::atan2(convertMatrix[0][2],-convertMatrix[1][2]);
        Angles(1) = std::atan2(std::sqrt(1-convertMatrix[2][2]*convertMatrix[2][2]),convertMatrix[2][2]);
        Angles(2) = std::atan2(convertMatrix[2][0],convertMatrix[2][1]);
        break;
    }
    case INT_ZYZ:
    {
        if(convertMatrix[2][2]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(0) = std::atan2(-convertMatrix[1][0],convertMatrix[0][0]);
            Angles(1) = 0;
            Angles(2) = 0;
            break;
        }
        else if(convertMatrix[2][0]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(0) = std::atan2(convertMatrix[1][0],convertMatrix[0][0]);
            Angles(1) = CV_PI;
            Angles(2) = 0;
            break;
        }
        Angles(0) = std::atan2(convertMatrix[1][2],convertMatrix[0][2]);
        Angles(1) = std::atan2(std::sqrt(1-convertMatrix[2][2]*convertMatrix[2][2]),convertMatrix[2][2]);
        Angles(2) = std::atan2(convertMatrix[2][1],-convertMatrix[2][0]);
        break;
    }

    case EXT_XYZ:
    {
        if(convertMatrix[2][0]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(-convertMatrix[0][1],convertMatrix[1][1]);
            Angles(1) = -CV_PI/2;
            Angles(0) = 0;
            break;
        }
        else if(convertMatrix[2][0]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(convertMatrix[1][2],convertMatrix[1][1]);
            Angles(1) = CV_PI/2;
            Angles(0) = 0;
            break;
        }
        Angles(0) = std::atan2(convertMatrix[2][1],convertMatrix[2][2]);
        Angles(1) = std::atan2(-convertMatrix[2][0],std::sqrt(1-convertMatrix[2][0]*convertMatrix[2][0]));
        Angles(2) = std::atan2(convertMatrix[1][0],convertMatrix[0][0]);


        break;
    }
    case EXT_XZY:
    {
        if(convertMatrix[1][0]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(0) = std::atan2(-convertMatrix[0][2],convertMatrix[0][0]);
            Angles(1) = CV_PI/2;
            Angles(2) = 0;
            break;
        }
        else if(convertMatrix[1][0]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(0) = std::atan2(-convertMatrix[0][2],convertMatrix[0][1]);
            Angles(1) = -CV_PI/2;
            Angles(2) = 0;
            break;
        }
        Angles(0) = std::atan2(-convertMatrix[1][2],convertMatrix[1][1]);
        Angles(1) = std::atan2(-convertMatrix[1][0],std::sqrt(1-convertMatrix[1][0]*convertMatrix[1][0]));
        Angles(2) = std::atan2(-convertMatrix[2][0],convertMatrix[0][0]);

        break;
    }
    case EXT_XYX:
    {
          if(convertMatrix[0][0]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(convertMatrix[2][1],convertMatrix[2][2]);
            Angles(1) = 0;
            Angles(0) = 0;
            break;
        }
        else if(convertMatrix[0][0]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(convertMatrix[1][2],convertMatrix[1][1]);
            Angles(1) = CV_PI;
            Angles(0) = 0;
            break;
        }
        Angles(0) = std::atan2(convertMatrix[0][1],convertMatrix[0][2]);
        Angles(1) = std::atan2(std::sqrt(1-convertMatrix[0][0]*convertMatrix[0][0]),convertMatrix[0][0]);
        Angles(2) = std::atan2(convertMatrix[1][0],-convertMatrix[2][0]);

        break;
    }
    case EXT_XZX:
    {
         if(convertMatrix[0][0]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(convertMatrix[2][1],convertMatrix[2][2]);
            Angles(1) = 0;
            Angles(0) = 0;
            break;
        }
        else if(convertMatrix[0][0]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(-convertMatrix[2][1],convertMatrix[2][2]);
            Angles(1) = CV_PI;
            Angles(0) = 0;
            break;
        }
        Angles(0) = std::atan2(convertMatrix[0][2],-convertMatrix[0][1]);
        Angles(1) = std::atan2(std::sqrt(1-convertMatrix[0][0]*convertMatrix[0][0]),convertMatrix[0][0]);
        Angles(2) = std::atan2(convertMatrix[2][0],convertMatrix[1][0]);
        break;
    }
    case EXT_YXZ:
    {
        if(convertMatrix[2][1]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(convertMatrix[1][0],convertMatrix[0][0]);
            Angles(1) = CV_PI/2;
            Angles(0) = 0;
            break;
        }
        else if(convertMatrix[2][1]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(convertMatrix[1][0],convertMatrix[0][0]);
            Angles(1) = -CV_PI/2;
            Angles(0) = 0;
            break;
        }
        Angles(0) = std::atan2(-convertMatrix[2][0],convertMatrix[2][2]);
        Angles(1) = std::atan2(convertMatrix[2][1],std::sqrt(1-convertMatrix[2][1]*convertMatrix[2][1]));
        Angles(2) = std::atan2(-convertMatrix[0][1],convertMatrix[1][1]);

        break;
    }
    case EXT_YZX:
    {
        if(convertMatrix[0][2]-1<1e-06)
        {
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(-convertMatrix[1][2],convertMatrix[2][2]);
            Angles(1) = -CV_PI/2;
            Angles(0) =0;
            break;
        }
        else if(convertMatrix[0][2]+1<1e-06)
        {
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(convertMatrix[2][0],convertMatrix[2][2]);
            Angles(1) = CV_PI/2;
            Angles(0) = 0;
            break;
        }

        Angles(0) = std::atan2(convertMatrix[0][2],convertMatrix[0][0]);
        Angles(1) = std::atan2(-convertMatrix[0][1],std::sqrt(1-convertMatrix[0][1]*convertMatrix[0][1]));
        Angles(2) = std::atan2(convertMatrix[2][1],convertMatrix[1][1]);
        break;
    }
    case EXT_YXY:
    {
        if(convertMatrix[1][1]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(convertMatrix[0][2],convertMatrix[0][0]);
            Angles(1) = 0;
            Angles(0) = 0;
            break;
        }
        else if(convertMatrix[1][1]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(-convertMatrix[2][0],convertMatrix[0][0]);
            Angles(1) = CV_PI;
            Angles(0) = 0;
            break;
        }
        Angles(0) = std::atan2(convertMatrix[1][0],-convertMatrix[1][2]);
        Angles(1) = std::atan2(std::sqrt(1-convertMatrix[1][1]*convertMatrix[1][1]),convertMatrix[1][1]);
        Angles(2) = std::atan2(convertMatrix[0][1],convertMatrix[2][1]);
        break;
    }
    case EXT_YZY:
    {
        if(convertMatrix[1][1]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(convertMatrix[0][2],convertMatrix[0][0]);
            Angles(1) = 0;
            Angles(0) = 0;
            break;
        }
        else if(convertMatrix[1][1]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(convertMatrix[0][2],convertMatrix[0][0]);
            Angles(1) = CV_PI;
            Angles(0) = 0;
            break;
        }
        Angles(0) = std::atan2(convertMatrix[1][2],convertMatrix[1][0]);
        Angles(1) = std::atan2(std::sqrt(1-convertMatrix[1][1]*convertMatrix[1][1]),convertMatrix[1][1]);
        Angles(2) = std::atan2(convertMatrix[2][1],-convertMatrix[0][1]);
        break;
    }
    case EXT_ZXY:
    {
        if(convertMatrix[1][2]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(-convertMatrix[0][1],convertMatrix[0][0]);
            Angles(1) = -CV_PI/2;
            Angles(0) = 0;
            break;
        }
        else if(convertMatrix[1][2]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(-convertMatrix[0][1],convertMatrix[0][0]);
            Angles(1) = CV_PI/2;
            Angles(0) = 0;
            break;
        }
        Angles(0) = std::atan2(convertMatrix[1][0],convertMatrix[1][1]);
        Angles(1) = std::atan2(-convertMatrix[1][2],std::sqrt(1-convertMatrix[1][2]*convertMatrix[1][2]));
        Angles(2) = std::atan2(convertMatrix[0][2],convertMatrix[2][2]);
        break;
    }
    case EXT_ZYX:
    {
        if(convertMatrix[0][2]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(convertMatrix[1][0],convertMatrix[1][1]);
            Angles(1) = CV_PI/2;
            Angles(0) = 0;
            break;
        }
        else if(convertMatrix[0][2]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2)= std::atan2(convertMatrix[1][0],convertMatrix[1][1]);
            Angles(1)= -CV_PI/2;
            Angles(0)=0;
            break;
        }

        Angles(0) = std::atan2(-convertMatrix[0][1],convertMatrix[0][0]);
        Angles(1) = std::atan2(convertMatrix[0][2],std::sqrt(1-convertMatrix[0][2]*convertMatrix[0][2]));
        Angles(2) = std::atan2(-convertMatrix[1][2], convertMatrix[2][2]);
        break;
    }
    case EXT_ZXZ:
    {
         if(convertMatrix[2][2]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(convertMatrix[1][0],convertMatrix[1][1]);
            Angles(1) = 0;
            Angles(0) = 0;
            break;
        }
        else if(convertMatrix[2][2]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(-convertMatrix[1][0],convertMatrix[0][0]);
            Angles(1) = CV_PI;
            Angles(0) = 0;
            break;
        }
        Angles(0) = std::atan2(convertMatrix[2][0],convertMatrix[2][1]);
        Angles(1) = std::atan2(std::sqrt(1-convertMatrix[2][2]*convertMatrix[2][2]),convertMatrix[2][2]);
        Angles(2) = std::atan2(convertMatrix[0][2],-convertMatrix[1][2]);

        break;
    }
    case EXT_ZYZ:
    {
         if(convertMatrix[2][2]-1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(convertMatrix[1][0],convertMatrix[0][0]);
            Angles(1) = 0;
            Angles(0) = 0;
            break;
        }
        else if(convertMatrix[2][0]+1<1e-06){
            cout<<"WARNING:Gimbal Lock happened." <<endl;;
            Angles(2) = std::atan2(convertMatrix[1][0],convertMatrix[0][0]);
            Angles(1) = CV_PI;
            Angles(0) = 0;
            break;
        }
        Angles(0) = std::atan2(convertMatrix[2][1],-convertMatrix[2][0]);
        Angles(1) = std::atan2(std::sqrt(1-convertMatrix[2][2]*convertMatrix[2][2]),convertMatrix[2][2]);
        Angles(2) = std::atan2(convertMatrix[1][2],convertMatrix[0][2]);
        break;
    }


    default:
        Angles = {0, 0, 0};
        break;
    }
    return Angles;

}

int main(){
    Vec3d angle = {0.324, 1.57, -0.897};
    EulerAnglesOrder order=INT_XYZ;
    Quatd dst = EularToAngles(angle,  order);
    std::cout<<"dst "<<dst<<std::endl;
    //std::cout<<"dst2 "<<dst2<<std::endl;
    Vec3d eulerangle = AnglesToEular(dst, order);
    std::cout<<"eulerangle "<< eulerangle<<std::endl;
    return 0;
}
