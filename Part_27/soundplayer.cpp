#include <soundplayer.h>

SoundPlayer::SoundPlayer(QWidget* pwgt) : QWidget(pwgt){
    QPushButton* pcmdOpen=new QPushButton("Open");
    QDial* pdiaVolume=new QDial;
    m_pcmdPlay=new QPushButton;
    m_pcmdStop=new QPushButton;
    m_psldPosition=new QSlider;
    m_plblCurrent=new QLabel(msecsToString(0));
    m_plblRemain=new QLabel(msecsToString(0));
    m_pmp=new QMediaPlayer;
    m_auo=new QAudioOutput;
    m_pcmdPlay->setEnabled(false);
    m_pcmdPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    m_pcmdStop->setEnabled(false);
    m_pcmdStop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    m_psldPosition->setRange(0,0);
    m_psldPosition->setOrientation(Qt::Horizontal);
    pdiaVolume->setRange(0,100);
    int nDefaultVolume=50;
    m_pmp->setAudioOutput(m_auo);
    m_auo->setVolume(0.5);
    pdiaVolume->setValue(nDefaultVolume);
    connect(pcmdOpen,&QPushButton::clicked,this,&SoundPlayer::slotOpen);
    connect(m_pcmdPlay,&QPushButton::clicked,this,&SoundPlayer::slotPlay);
    connect(m_pcmdStop,&QPushButton::clicked,m_pmp,&QMediaPlayer::stop);
    connect(pdiaVolume,&QDial::valueChanged,this,&SoundPlayer::slotVolumeChanged);
    connect(this,&SoundPlayer::sig_volumeChanged,m_auo,&QAudioOutput::setVolume);
    connect(m_psldPosition,&QSlider::sliderMoved,this,&SoundPlayer::slotSetMediaPosition);
    connect(m_pmp,&QMediaPlayer::positionChanged,this,&SoundPlayer::slotSetSliderPosition);
    connect(m_pmp,&QMediaPlayer::durationChanged,this,&SoundPlayer::slotSetDuration);
    connect(m_pmp,&QMediaPlayer::playbackStateChanged,this,&SoundPlayer::slotStatusChanged);
    QHBoxLayout* phbxPlayContols=new QHBoxLayout;
    phbxPlayContols->addWidget(pcmdOpen);
    phbxPlayContols->addWidget(m_pcmdPlay);
    phbxPlayContols->addWidget(m_pcmdStop);
    phbxPlayContols->addWidget(pdiaVolume);
    QHBoxLayout* phbxTimeControls=new QHBoxLayout;
    phbxTimeControls->addWidget(m_plblCurrent);
    phbxTimeControls->addWidget(m_psldPosition);
    phbxTimeControls->addWidget(m_plblRemain);
    m_pvbx=new QVBoxLayout;
    m_pvbx->addLayout(phbxPlayContols);
    m_pvbx->addLayout(phbxTimeControls);
    setLayout(m_pvbx);
}

void SoundPlayer::slotOpen(){
    QString strFile=QFileDialog::getOpenFileName(this,"Open File");
    if(!strFile.isEmpty()){
        m_pmp->setSource(QUrl::fromLocalFile(strFile));
        m_pcmdPlay->setEnabled(true);
        m_pcmdStop->setEnabled(true);
    }
}

void SoundPlayer::slotPlay(){
    switch(m_pmp->playbackState()){
        case QMediaPlayer::PlayingState:
            m_pmp->pause();
            break;
        default:
            m_pmp->play();
            break;
    }
}

void SoundPlayer::slotStatusChanged(QMediaPlayer::PlaybackState state){
    switch(state){
        case QMediaPlayer::PlayingState:
            m_pcmdPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
            break;
        default:
            m_pcmdPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
            break;
    }
}

void SoundPlayer::slotSetMediaPosition(int n){
    m_pmp->setPosition(n);
}

QString SoundPlayer::msecsToString(qint64 n){
    int nHours=(n/(60*60*1000));
    int nMinutes=((n%(60*60*1000))/(60*1000));
    int nSeconds=((n%(60*1000))/1000);
    return QTime(nHours,nMinutes,nSeconds).toString("hh:mm:ss");
}

void SoundPlayer::slotSetDuration(qint64 n){
    m_psldPosition->setRange(0,n);
    m_plblCurrent->setText(msecsToString(0));
    m_plblRemain->setText(msecsToString(n));
}

void SoundPlayer::slotSetSliderPosition(qint64 n){
    m_psldPosition->setValue(n);
    m_plblCurrent->setText(msecsToString(n));
    int nDuration=m_psldPosition->maximum();
    m_plblRemain->setText(msecsToString(nDuration-n));
}

void SoundPlayer::slotVolumeChanged(int val){
    float volume=static_cast<float>(val);
    emit sig_volumeChanged(volume/100);
}