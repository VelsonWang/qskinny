/******************************************************************************
 * QSkinny - Copyright (C) 2016 Uwe Rathmann
 * This file may be used under the terms of the 3-clause BSD License
 *****************************************************************************/

#ifndef SPEEDOMETERSKINLET_H
#define SPEEDOMETERSKINLET_H

#include <QskSkinlet.h>

class Speedometer;

class SpeedometerSkinlet : public QskSkinlet
{
    Q_GADGET

  public:
    enum NodeRole
    {
        PanelRole,
        LabelsRole,
        NeedleRole
    };

    Q_INVOKABLE SpeedometerSkinlet( QskSkin* skin = nullptr );
    ~SpeedometerSkinlet() override;

    QRectF subControlRect( const QskSkinnable*,
        const QRectF&, QskAspect::Subcontrol ) const override;

  protected:
    virtual QSGNode* updateSubNode( const QskSkinnable*,
        quint8 nodeRole, QSGNode* node ) const override;

  private:
    QSGNode* updatePanelNode( const Speedometer*, QSGNode* ) const;
    QSGNode* updateLabelsNode( const Speedometer*, QSGNode* ) const;
    QSGNode* updateNeedleNode( const Speedometer*, QSGNode* ) const;
};

#endif
