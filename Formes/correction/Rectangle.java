import java.awt.Color;
import java.awt.Graphics;

public class Rectangle extends FormeColoree implements Forme {

	protected int m_x;
	protected int m_y;
	protected int m_w;
	protected int m_h;

	public Rectangle(int mX, int mY, int mW, int mH, Color c) {
		super(c);
		m_x = mX;
		m_y = mY;
		m_w = mW;
		m_h = mH;
	}

	@Override
	public void redessiner(Graphics g) {
		g.setColor(m_color);
		g.fillRect(m_x, m_y, m_w, m_h);
	}

}
