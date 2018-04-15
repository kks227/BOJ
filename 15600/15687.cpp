class Rectangle {
	private:
		int width, height;
	public:
		Rectangle(int width, int height) {
            this->width = width;
            this->height = height;
		}
		int get_width() const {
            return width;
		}
		int get_height() const {
            return height;
		}
		void set_width(int width) {
            if(width > 0 && width <= 1000) this->width = width;
		}
		void set_height(int height) {
            if(height > 0 && height <= 2000) this->height = height;
		}
		int area() const {
            return width * height;
		}
		int perimiter() const {
            return (width + height) * 2;
		}
		bool is_square() const {
            return (width == height);
		}
};
