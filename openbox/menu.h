#ifndef __menu_h
#define __menu_h

#include <glib.h>

typedef struct Menu {
    char *label;
    
    GList *entries;
    /* GList *tail; */

    /* ? */
    gboolean shown;
    gboolean invalid;

    struct Menu *parent;

    /* waste o' pointers */
    void (*show)( /* some bummu */);
    void (*hide)( /* some bummu */);
    void (*update)( /* some bummu */);
    void (*mouseover)( /* some bummu */);
    void (*selected)( /* some bummu */);
} Menu;

typedef enum MenuEntryRenderType {
    MenuEntryRenderType_None = 0,
    MenuEntryRenderType_Submenu 1 << 0,
    MenuEntryRenderType_Boolean 1 << 1,
    MenuEntryRenderType_Separator 1 << 2,
    
    MenuEntryRenderType_Other 1 << 7
} MenuEntryType;


typedef struct {
    char *label;
    Menu *parent;

    Action action;    
    
    MenuEntryRenderType render_type;
    gboolean enabled;
    gboolean boolean_value;
    gpointer render_data;

    Menu *submenu;
} MenuEntry;

Menu *menu_new(char *label, Menu *parent);
MenuEntry *menu_entry_new_full(char *label, Action *action,
                          MenuEntryRenderType render_type,
                          gpointer render_data, gpointer submenu);

#define menu_entry_new(label, action) \
  menu_entry_new(label, action, MenuEntryRenderType_None, NULL, NULL)

void menu_entry_set_submenu(MenuEntry *entry, Menu *submenu);

void menu_add_entry(Menu *menu, MenuEntry *entry);
#endif
