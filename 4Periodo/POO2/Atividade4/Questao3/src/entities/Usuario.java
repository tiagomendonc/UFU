// Classe Usuario para diferenciar entre usuários regulares e administradores.

package entities;

public class Usuario {
	private String nome;
	private boolean isAdmin;
	private boolean temAcessoArquivosConfidenciais;
	
	public Usuario(String nome, boolean isAdmin, boolean temAcessoArquivosConfidenciais) {
		this.nome = nome;
		this.isAdmin = isAdmin;
		this.temAcessoArquivosConfidenciais = temAcessoArquivosConfidenciais;
	}
	
	public boolean temPermissaoVisualizar() {
		return isAdmin || temAcessoArquivosConfidenciais;
	}
	
	public boolean temPermissaoBaixar() {
		return isAdmin || temAcessoArquivosConfidenciais;
	}
}
