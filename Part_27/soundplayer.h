#pragma once

#include <QtWidgets>
#include <QtMultimedia>

class SoundPlayer : public QWidget{
    Q_OBJECT

    protected:
        QMediaPlayer* m_pmp;
        QAudioOutput* m_auo;
        QVBoxLayout* m_pvbx;
    
    private:
        QPushButton* m_pcmdPlay;
        QPushButton* m_pcmdStop;
        QSlider* m_psldPosition;
        QLabel* m_plblCurrent;
        QLabel* m_plblRemain;
        QString msecsToString(qint64 n);

    public:
        SoundPlayer(QWidget* pwgt=nullptr);

    signals:
        void sig_volumeChanged(float);

    private slots:
        void slotOpen();
        void slotPlay();
        void slotSetSliderPosition(qint64);
        void slotSetMediaPosition(int);
        void slotSetDuration(qint64);
        void slotStatusChanged(QMediaPlayer::PlaybackState);
        void slotVolumeChanged(int);
};