#include <QtMultimediaWidgets>
#include <videoplayer.h>

VideoPlayer::VideoPlayer(QWidget* pwgt) : SoundPlayer(pwgt){
    QVideoWidget* pvw=new QVideoWidget;
    pvw->setMinimumSize(300,300);
    m_pvbx->addWidget(pvw);
    m_pmp->setVideoOutput(pvw);
    connect(m_pmp,&QMediaPlayer::playbackStateChanged,this,&VideoPlayer::slotStateChanged);

}

void VideoPlayer::slotStateChanged(QMediaPlayer::PlaybackState st){
    if (st == QMediaPlayer::PlayingState) {
        resize(size() + QSize(1, 1));
        resize(size() - QSize(1, 1));
    }
}