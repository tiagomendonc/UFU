/*
 * Imagine que você está trabalhando em um sistema de reprodução de áudio que possui várias classes de reprodutores de áudio, 
 * cada uma com sua própria interface. 
 * No entanto, você deseja criar um novo componente de alto nível, um "PlayerUniversal," que pode reproduzir arquivos de áudio em formatos diferentes, 
 * independentemente do reprodutor subjacente.

	Problema:
	
	1 -Existem várias classes de reprodutores de áudio (por exemplo, MP3Player, WAVPlayer, FLACPlayer) com interfaces diferentes.
	
	2- Você deseja criar uma classe "PlayerUniversal" que pode reproduzir arquivos de áudio em qualquer formato, independentemente do reprodutor subjacente.
	
	3- A classe "PlayerUniversal" espera uma interface comum, mas os reprodutores existentes não a implementam.
	
	Para resolver este problema, você pode usar o padrão Adapter para criar adaptadores para cada reprodutor de áudio existente, 
	permitindo que eles sejam usados pelo "PlayerUniversal."
*/


package app;

import interfaces.*;
import entities.*;

public class Main {
    public static void main(String[] args) {
        MP3Player mp3Player = new MP3Player();

        AudioPlayer mp3PlayerAdapter = new MP3PlayerAdapter(mp3Player);

        PlayerUniversal universalPlayer = new PlayerUniversal(mp3PlayerAdapter);

        System.out.println("Reprodução Universal:");
        universalPlayer.reproduzirAudio();
    }
}
