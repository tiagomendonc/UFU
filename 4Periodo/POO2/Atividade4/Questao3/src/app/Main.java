/* 	Problema Proposto: Sistema de Gerenciamento de Arquivos Seguro	
 * 
 * 	Imagine que está desenvolvendo um sistema de gerenciamento de arquivos para uma empresa. Existem vários tipos de arquivos, 
 	como documentos, imagens e vídeos, e diferentes níveis de acesso, incluindo usuários regulares e administradores.
 	Porém, usuários regulares só podem visualizar e fazer download de arquivos, enquanto os administradores podem fazer upload, visualizar e excluir arquivos.
 	Além disso, os arquivos confidenciais devem ser protegidos e só podem ser acessados por administradores.
*/


package app;

import interfaces.Arquivo;
import entities.*;

public class Main {
	public static void main(String[] args) {
		Usuario usuarioRegular = new Usuario("João", false, false);
		Usuario usuarioAdmin = new Usuario("Maria", true, true);
		
		Arquivo arquivo1 = new ProxyArquivo("DocumentoConfidencial.pdf", usuarioRegular);
		Arquivo arquivo2 = new ProxyArquivo("RelatorioAnual.pdf", usuarioAdmin);
		
		arquivo1.visualizar(); // Acesso negado para usuário regular
        arquivo1.baixar();     // Acesso negado para usuário regular

        arquivo2.visualizar(); // Acesso permitido para administrador
        arquivo2.baixar();     // Acesso permitido para administrador
	}
}

/*
 *	Neste exemplo, o padrão Proxy é usado para controlar o acesso a arquivos, permitindo que apenas usuários autorizados visualizem e 
 *	baixem os arquivos. Os proxies (ProxyArquivo) verificam as permissões dos usuários antes de permitir a execução das operações em arquivos reais (ArquivoReal). 
 *	Isso garante que o acesso a arquivos confidenciais seja restrito aos administradores e demonstra como o padrão Proxy pode ser usado para proteger 
 *	recursos sensíveis em um sistema.
 */
