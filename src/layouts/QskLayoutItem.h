/******************************************************************************
 * QSkinny - Copyright (C) 2016 Uwe Rathmann
 * This file may be used under the terms of the QSkinny License, Version 1.0
 *****************************************************************************/

#ifndef QSK_LAYOUT_ITEM_H
#define QSK_LAYOUT_ITEM_H

#include "QskGlobal.h"
#include "QskSizePolicy.h"
#include <QtGui/private/qgridlayoutengine_p.h>

class QQuickItem;

class QskLayoutItem : public QGridLayoutItem
{
    using Inherited = QGridLayoutItem;

public:
    enum UpdateMode
    {
        UpdateNone,
        UpdateWhenVisible,
        UpdateAlways
    };

    QskLayoutItem( QQuickItem* item, int row, int column,
        int rowSpan = 1, int columnSpan = 1 );

    QskLayoutItem( const QSizeF& size, int stretch, int row, int column );

    virtual ~QskLayoutItem();

    QQuickItem* item();
    const QQuickItem* item() const;

    virtual QLayoutPolicy::Policy sizePolicy( Qt::Orientation ) const override final;
    virtual QSizeF sizeHint( Qt::SizeHint, const QSizeF& ) const override final;
    virtual void setGeometry( const QRectF& ) override final;

    virtual bool hasDynamicConstraint() const override final;
    virtual Qt::Orientation dynamicConstraintOrientation() const override final;

    virtual bool isIgnored() const override final;
    virtual QLayoutPolicy::ControlTypes controlTypes( LayoutSide side ) const override final;

    bool retainSizeWhenHidden() const;
    void setRetainSizeWhenHidden( bool on );

    UpdateMode updateMode() const;
    void setUpdateMode( UpdateMode );

    QSizeF spacingHint() const;
    void setSpacingHint( const QSizeF& );

    bool isGeometryDirty() const;

    bool hasUnlimitedSpan() const;
    bool hasUnlimitedSpan( Qt::Orientation orientation ) const;

private:
    bool m_isGeometryDirty : 1;
    bool m_isStretchable : 1;
    bool m_retainSizeWhenHidden : 1;
    bool m_unlimitedRowSpan : 1;
    bool m_unlimitedColumnSpan : 1;
    UpdateMode m_updateMode : 2;

    QSizeF m_spacingHint;

    QQuickItem* m_item;
};

inline QQuickItem* QskLayoutItem::item()
{
    return m_item;
}

inline const QQuickItem* QskLayoutItem::item() const
{
    return m_item;
}

inline bool QskLayoutItem::isGeometryDirty() const
{
    return m_isGeometryDirty;
}

inline bool QskLayoutItem::hasUnlimitedSpan( Qt::Orientation orientation ) const
{
    return ( orientation == Qt::Horizontal )
           ? m_unlimitedColumnSpan : m_unlimitedRowSpan;
}

inline bool QskLayoutItem::hasUnlimitedSpan() const
{
    return m_unlimitedColumnSpan || m_unlimitedRowSpan;
}

#endif