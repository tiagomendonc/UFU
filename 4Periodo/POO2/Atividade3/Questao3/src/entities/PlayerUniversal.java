package entities;

import interfaces.AudioPlayer;

public class PlayerUniversal {
    private AudioPlayer player;

    public PlayerUniversal(AudioPlayer player) {
        this.player = player;
    }

    public void reproduzirAudio() {
        player.reproduzir();
    }
}