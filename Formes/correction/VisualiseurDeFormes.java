import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class VisualiseurDeFormes extends JFrame {
	private Random m_random;

	private Vector m_formes;

	private Vector m_temp_formes;

	private ZoneDeDessin m_panneau_dessin;

	private JPanel m_panneau_boutons;

	private Color m_color;

	class BoutonCercleAction extends Bouton_action implements ActionListener {

		BoutonCercleAction(VisualiseurDeFormes visu) {
			super(visu);
		}

		public void actionPerformed(ActionEvent e) {
			Random r = getRandom();
			Cercle c = new Cercle(r.nextInt(940), r.nextInt(700), r.nextInt(70) + 20, m_color);
			getFormes().add(c);
			repaint();
		}
	}

	class BoutonRectAction extends Bouton_action implements ActionListener {

		BoutonRectAction(VisualiseurDeFormes visu) {
			super(visu);
		}

		@Override
		public void actionPerformed(ActionEvent arg0) {
			Random r = getRandom();
			Rectangle rect = new Rectangle(r.nextInt(900), r.nextInt(600), r.nextInt(200), r.nextInt(200), m_color);

			getFormes().add(rect);
			repaint();

		}

	}

	class BoutonResetAction extends Bouton_action implements ActionListener {

		BoutonResetAction(VisualiseurDeFormes visu) {
			super(visu);
		}

		@Override
		public void actionPerformed(ActionEvent e) {

			getFormes().clear();
			repaint();
		}

	}

	class BoutonRandomAction extends Bouton_action implements ActionListener {
		JButton m_b1, m_b2;

		BoutonRandomAction(VisualiseurDeFormes visu, JButton b1, JButton b2) {
			super(visu);
			m_b1 = b1;
			m_b2 = b2;
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			Random r = getRandom();
			int randint = r.nextInt(100);
			if (randint < 50) {
				m_b1.doClick();
				/*
				 * Rectangle rect = new Rectangle( r.nextInt( 900 ), r.nextInt( 600 ),
				 * r.nextInt(200), r.nextInt(200), m_color); getFormes().add( rect);
				 */
			} else {
				m_b2.doClick();
				/*
				 * Cercle c = new Cercle( r.nextInt( 940 ), r.nextInt( 700 ), r.nextInt( 70 )+
				 * 20 , m_color); getFormes().add( c );
				 */
			}
			repaint();
		}

	}

	class BoutonChangeColorAction extends Bouton_action implements ActionListener {

		BoutonChangeColorAction(VisualiseurDeFormes visu) {
			super(visu);

		}

		@Override
		public void actionPerformed(ActionEvent e) {
			Random r = getRandom();
			m_color = new Color(r.nextInt(256), r.nextInt(256), r.nextInt(256));

		}

	}

	public VisualiseurDeFormes(String title) {
		super(title);

		m_formes = new Vector();
		m_temp_formes = new Vector();
		m_random = new Random();
		setPreferredSize(new Dimension(1024, 768));
		setLayout(new BorderLayout());
		m_panneau_dessin = new ZoneDeDessin();
		m_panneau_dessin.setFormes(m_formes);
		m_panneau_dessin.setTempFormes(m_temp_formes);
		m_panneau_boutons = new JPanel();
		JLabel label = new JLabel("Visualiseur de Formes");
		getContentPane().add(label, BorderLayout.NORTH);
		getContentPane().add(m_panneau_boutons, BorderLayout.SOUTH);
		getContentPane().add(m_panneau_dessin, BorderLayout.CENTER);

		// m_formes.add(new String("text"));

		BoutonCercleAction action_cercle = new BoutonCercleAction(this);
		JButton b1 = new JButton("Cercle");
		b1.addActionListener(action_cercle);
		m_panneau_boutons.add(b1);

		BoutonRectAction action_rect = new BoutonRectAction(this);
		JButton b2 = new JButton("Rectangle");
		b2.addActionListener(action_rect);
		m_panneau_boutons.add(b2);

		BoutonResetAction action_reset = new BoutonResetAction(this);
		JButton b3 = new JButton("Reset");
		b3.addActionListener(action_reset);
		m_panneau_boutons.add(b3);

		BoutonRandomAction action_random = new BoutonRandomAction(this, b1, b2);
		JButton b4 = new JButton("Random");
		b4.addActionListener(action_random);
		m_panneau_boutons.add(b4);

		m_color = new Color(255, 255, 255);

		BoutonChangeColorAction action_color = new BoutonChangeColorAction(this);
		JButton b5 = new JButton("Color");
		b5.addActionListener(action_color);
		m_panneau_boutons.add(b5);

		RectangleParDragSouris rectDrag = new RectangleParDragSouris(this);
		m_panneau_dessin.addMouseListener(rectDrag);

		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	public Color getM_color() {
		return m_color;
	}

	public void setM_color(Color mColor) {
		m_color = mColor;
	}

	public static void main(String[] args) {
		VisualiseurDeFormes visu = new VisualiseurDeFormes("preums");
		// Display the window.
		visu.pack();
		visu.setVisible(true);

		VisualiseurDeFormes visu2 = new VisualiseurDeFormes("deuz");
		// Display the window.
		visu2.pack();
		visu2.setVisible(true);
	}

	public Vector getFormes() {
		return m_formes;
	}

	public Vector getTempFormes() {
		return m_temp_formes;
	}

	public Random getRandom() {
		return m_random;
	}

}
