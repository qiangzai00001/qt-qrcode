/****************************************************************************
 *
 * Copyright (c) 2015 Daniel San, All rights reserved.
 *
 *    Contact: daniel.samrocha@gmail.com
 *       File: qtqrcode.h
 *     Author: daniel
 * Created on: 03/02/2015
 *    Version:
 *
 * This file is part of the Qt QRCode library.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.
 *
 ***************************************************************************/

#ifndef QTQRCODE_HPP
#define QTQRCODE_HPP

#include <QByteArray>
#include <QSharedDataPointer>

#include "qrencode.h"

class QtQrCodeData;

class QtQrCode
{
public:
    enum Proportion {
        NormalProportion = 0,
        MicroProportion = 1
    };
    enum EncodeMode {
        DataMode = 0,
        StringMode,
        KanjiMode,
    };
    enum ErrorCorrectionLevel {
        LowLevel = QR_ECLEVEL_L,
        MediumLevel = QR_ECLEVEL_M,
        QuartileLevel = QR_ECLEVEL_Q,
        HighLevel = QR_ECLEVEL_H
    };
    QtQrCode();
    QtQrCode(const QByteArray &data, int version,
             ErrorCorrectionLevel errorCorrectionLevel = LowLevel);
    QtQrCode(const QByteArray &data, int version, EncodeMode encodeMode = StringMode);
    QtQrCode(const QByteArray &data, int version, int margin, EncodeMode encodeMode,
             Proportion proportion, Qt::CaseSensitivity caseSensitivity,
             ErrorCorrectionLevel errorCorrectionLevel);
    QtQrCode(const QtQrCode &);
    QtQrCode &operator=(const QtQrCode &);
    ~QtQrCode();

    int width() const;

    int margin() const;
    void setMargin(int margin);

    int version() const;
    void setVersion(int version);

    QByteArray data() const;
    void setData(const QByteArray &data);

    EncodeMode encodeMode() const;
    void setEncodeMode(QtQrCode::EncodeMode encodeMode);

    Proportion proportion() const;
    void setProportion(QtQrCode::Proportion proportion);

    Qt::CaseSensitivity caseSensitivity() const;
    void setCaseSensitivity(Qt::CaseSensitivity caseSensitivity);

    ErrorCorrectionLevel errorCorrectionLevel() const;
    void setErrorCorrectionLevel(QtQrCode::ErrorCorrectionLevel errorCorrectionLevel);

protected:
    QSharedDataPointer<QtQrCodeData> d;
    void encode();
private:
    void setBaseQrCodeData(QRcode *qrCode);
    void encodeData();
    void encodeString();
    void encodeSKanji();
};

#endif // QTQRCODE_HPP
