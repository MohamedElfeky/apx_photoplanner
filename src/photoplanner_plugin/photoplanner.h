#ifndef APXPHOTOPLANNER_H
#define APXPHOTOPLANNER_H

#include <QObject>
#include <memory>
#include "Fact.h"
#include "points.h"
#include "PhotoUavModel.h"
#include "PhotoCameraModel.h"

class ApxPhotoplanner: public Fact
{
    Q_OBJECT
    Q_PROPERTY(Points *points READ getPoints CONSTANT)
public:
    ApxPhotoplanner(Fact *parent = nullptr);
    Points* getPoints();

public slots:
    void onLoadingFinished();
    void onAddPhotoplannerPointTriggered();

private:
    std::unique_ptr<Points> m_points;
    std::unique_ptr<Fact> m_addPhotoplannerPoint;
    aero_photo::PhotoCameraModel m_cameraModel;
    aero_photo::PhotoUavModel m_uavModel;

    void onPointsRowsInserted(const QModelIndex &parent, int first, int last);
};

#endif // APXPHOTOPLANNER_H