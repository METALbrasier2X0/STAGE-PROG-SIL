import java.awt.Point;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.lang.Math;

public class RectangleParDragSouris extends MouseAdapter {

	private Point m_coin_down;
	private Point m_coin_up;
	private VisualiseurDeFormes m_visu;
	private Boolean m_in_movement;

	public RectangleParDragSouris(VisualiseurDeFormes visu) {
		super();
		m_visu = visu;
		m_in_movement = false;
	}

	@Override
	public void mousePressed(MouseEvent arg0) {
		m_coin_down = arg0.getPoint();
		m_in_movement = true;
		super.mousePressed(arg0);
	}

	@Override
	public void mouseDragged(MouseEvent e) {
		if (m_in_movement) {
			m_coin_up = e.getPoint();
			int rectX = (int) m_coin_down.getX();
			if (m_coin_up.getX() < m_coin_down.getX())
				rectX = (int) m_coin_up.getX();
			int rectY = (int) m_coin_down.getY();
			if (m_coin_up.getY() < m_coin_down.getY())
				rectY = (int) m_coin_up.getY();

			Rectangle newRect = new Rectangle(rectX, rectY, Math.abs((int) (m_coin_up.getX() - m_coin_down.getX())),
					Math.abs((int) (m_coin_up.getY() - m_coin_down.getY())), m_visu.getM_color());
			m_visu.getFormes().add(newRect);
			m_visu.repaint();
		}
		super.mouseDragged(e);
	}

	@Override
	public void mouseReleased(MouseEvent arg0) {
		m_in_movement = false;
		m_coin_up = arg0.getPoint();
		int rectX = (int) m_coin_down.getX();
		if (m_coin_up.getX() < m_coin_down.getX())
			rectX = (int) m_coin_up.getX();
		int rectY = (int) m_coin_down.getY();
		if (m_coin_up.getY() < m_coin_down.getY())
			rectY = (int) m_coin_up.getY();

		Rectangle newRect = new Rectangle(rectX, rectY, Math.abs((int) (m_coin_up.getX() - m_coin_down.getX())),
				Math.abs((int) (m_coin_up.getY() - m_coin_down.getY())), m_visu.getM_color());
		m_visu.getTempFormes().clear();
		m_visu.getFormes().add(newRect);
		m_visu.repaint();
		super.mouseReleased(arg0);
	}
}
