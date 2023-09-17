// Classe Proxy (ProxyArquivo) que controla o acesso aos arquivos.

package entities;

import interfaces.Arquivo;

public class ProxyArquivo implements Arquivo {
	private ArquivoReal arquivoReal;
	private Usuario usuario;
	
	public ProxyArquivo(String nome, Usuario usuario) {
		this.arquivoReal = new ArquivoReal(nome);
		this.usuario = usuario;
	}
	
	@Override
	public void visualizar() {
		if(usuario.temPermissaoVisualizar()) {
			arquivoReal.visualizar();
		} else {
            System.out.println("Você não tem permissão para visualizar este arquivo.");
		}
	}
	
	@Override
	public void baixar() {
		if(usuario.temPermissaoBaixar()) {
			arquivoReal.baixar();
		} else {
			System.out.println("Você não tem permissão para baixar este arquivo.");
		}
	}
}
