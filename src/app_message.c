#include <pebble.h>

static Window *window;
static TextLayer *text_layer;

// Key values for AppMessage Dictionary
enum {
    MESSAGE_KEY = 0
};

<<<<<<< HEAD
int main( void ) {
    init();
    app_event_loop();
    deinit();
}
=======
// Called when a message is received from PebbleKitJS
static void in_received_handler(DictionaryIterator *received, void *context) {
	Tuple *tuple;
	
	tuple = dict_find(received, MESSAGE_KEY);
	if(tuple) {
		APP_LOG(APP_LOG_LEVEL_DEBUG, "Received Message: %s", tuple->value->cstring);
        text_layer_set_text(text_layer, tuple->value->cstring);
	}}
>>>>>>> FETCH_HEAD

void init(void) {
    window = window_create();
    window_set_background_color(window, GColorBlack);
<<<<<<< HEAD
    window_stack_push(window, true);

    // Register AppMessage handlers
    app_message_register_inbox_received(in_received_handler); 
    app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());
=======
	window_stack_push(window, true);
	
	// Register AppMessage handlers
	app_message_register_inbox_received(in_received_handler); 
		
	app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());
>>>>>>> FETCH_HEAD

    Layer *window_layer = window_get_root_layer(window);
    GRect bounds = layer_get_bounds(window_layer);

    text_layer = text_layer_create((GRect) { .origin = { 0, 50 }, .size = { bounds.size.w, 60 } });
    text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
    text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_ROBOTO_BOLD_SUBSET_49));
    text_layer_set_text_color(text_layer, GColorWhite);
    text_layer_set_background_color(text_layer, GColorBlack);
    layer_add_child(window_layer, text_layer_get_layer(text_layer));
}

// Called when a message is received from PebbleKitJS
static void in_received_handler(DictionaryIterator *received, void *context) {
    Tuple *tuple;
    tuple = dict_find(received, MESSAGE_KEY);
    if(tuple) {
        APP_LOG(APP_LOG_LEVEL_DEBUG, "Received Message: %s", tuple->value->cstring);
        text_layer_set_text(text_layer, tuple->value->cstring);
    }
}

void deinit(void) {
    app_message_deregister_callbacks();
    text_layer_destroy(text_layer);
    window_destroy(window);
}
