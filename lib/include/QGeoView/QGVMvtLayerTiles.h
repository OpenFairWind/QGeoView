#ifndef QGVMVTLAYERTILES_H
#define QGVMVTLAYERTILES_H

#include "QGVVectorTilesOnline.h"

class QGV_LIB_DECL QGVMvtLayerTiles : public QGVVectorTilesOnline
{
    Q_OBJECT

public:
    QGVMvtLayerTiles(const quint32&);
    QGVMvtLayerTiles(const quint32&, const QString&);

    void setUrl(const QString& url);
    QString getUrl() const;

    void setTileSize(const quint32&);
    quint32 getTileSize() const;

    void setTileType(const QString&);
    QString getTileType() const;

protected:
    QList<QGVDrawItem*> buildShapes(const QGV::GeoTilePos&, const QByteArray&) override;

private:
    int minZoomlevel() const override;
    int maxZoomlevel() const override;
    QString tilePosToUrl(const QGV::GeoTilePos& tilePos) const override;

private:
    QString mUrl;
    quint32 mTileSize;
    QString mTileType;
};

#endif // QGVMVTLAYERTILES_H