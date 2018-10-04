import java.util.Vector;
import java.awt.Graphics;
import javax.swing.JPanel;

public class ZoneDeDessin extends JPanel {
	private Vector m_formes;
	private Vector m_temp_formes;

	public void setTempFormes(Vector mTempFormes) {
		m_temp_formes = mTempFormes;
	}

	public ZoneDeDessin() {
	}

	public void setFormes(Vector formes) {
		m_formes = formes;
	}

	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		if (m_formes != null) {
			for (int i = 0; i < m_formes.size(); i++) {
				Forme f = (Forme) m_formes.get(i);
				f.redessiner(g);
			}
		}
		if (m_temp_formes != null) {
			for (int i = 0; i < m_temp_formes.size(); i++) {
				Forme f = (Forme) m_temp_formes.get(i);
				f.redessiner(g);
			}
		}
	}
}
