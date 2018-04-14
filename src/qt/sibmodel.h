// Copyright (c) 2015 The Ilixomtest developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ILTMODEL_H
#define	ILTMODEL_H

#include "iltdb.h"

#include <QObject>

#include <QNetworkReply>

class QNetworkAccessManager;
class QResource;


/** Interface to Ilixomtest DB from Qt view code. */
class SibModel : public QObject
{
    Q_OBJECT

public:
    explicit SibModel(CSibDB *iltdb, QObject *parent = 0);
    ~SibModel();

    void fetch(); 
    void fetch_url(int _idx);
    bool saveResourceWithMD5();
    bool readResourceWithMD5();
    
private:
    enum ST {
        ST_INIT,
        ST_LOADING_RCC,
        ST_LOADING_MD5,
        ST_LOADED,
        ST_ERROR,
    };
    
    QString res_prefix;
    CSibDB *iltDB;    
    QNetworkAccessManager* net_manager;
    QByteArray rccData;
    QString rccMD5;
    ST state;
    int try_idx;
    QString data_url;
    
Q_SIGNALS:
    void resourceReady(std::string res_root);
    

public Q_SLOTS:
    void replyFinished(QNetworkReply* p_reply);
    
private:
    void loadLocalResource();
    void loadFromDB();
    bool registerRes();
        
};

#endif	/* ILTMODEL_H */

