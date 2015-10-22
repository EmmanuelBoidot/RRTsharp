#ifndef WINDOW_H
#define WINDOW_H

#include <vector>
#include <queue>

#include <QWidget>

#include "RRTsharp.h"

class Window : public QWidget
{
    Q_OBJECT
    
public:
    Window(QWidget *parent = 0);
    ~Window();
    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void paintEvent(QPaintEvent *event);
    void setPlannerPtr(ompl::base::PlannerPtr planner){this->planner = planner;}
//    void setS(ompl::base::PlannerPtr planner){this->planner = planner;}

    ompl::base::PlannerPtr planner;

//    std::vector<ompl::geometric::RRTsharp::Motion*> motions;
//    std::priority_queue<ompl::geometric::RRTsharp::Motion*> rewiringCandidates;
};

#endif // WINDOW_H
