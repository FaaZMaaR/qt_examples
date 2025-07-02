#pragma once

#include <soundplayer.h>

class VideoPlayer : public SoundPlayer{
    Q_OBJECT

    public:
        VideoPlayer(QWidget* pwgt=nullptr);

    public slots:
        void slotStateChanged(QMediaPlayer::PlaybackState);
};