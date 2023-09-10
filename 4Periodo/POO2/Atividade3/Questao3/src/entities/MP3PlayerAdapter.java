package entities;

import interfaces.AudioPlayer;

public class MP3PlayerAdapter implements AudioPlayer {
    private MP3Player mp3Player;

    public MP3PlayerAdapter(MP3Player mp3Player) {
        this.mp3Player = mp3Player;
    }

    @Override
    public void reproduzir() {
        mp3Player.playMP3();
    }
}
