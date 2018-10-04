import java.awt.Color;
import java.awt.Graphics;

public class Cercle extends FormeColoree implements Forme {
	protected int m_x;
	protected int m_y;
	protected int m_r;

	public Cercle(int x, int y, int r, Color c) {
		super(c);
		m_x = x;
		m_y = y;
		m_r = r;
	}

	public void redessiner(Graphics g) {
		g.setColor(m_color);
		g.fillOval(m_x - m_r, m_y - m_r, 2 * m_r, 2 * m_r);
	}

}
