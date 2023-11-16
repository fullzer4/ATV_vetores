use ratatui::{prelude::*, widgets::*};

pub fn ui(frame: &mut Frame) {
    frame.render_widget(
        Paragraph::new("Hello World!")
            .block(Block::default().borders(Borders::ALL)),
        frame.size(),
    );
}