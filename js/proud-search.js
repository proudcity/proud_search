
(function($, Drupal) {
  Drupal.behaviors.proud_search = {
    attach: function(context, settings) {

      var proud_autocomplete = function(value, selector) {
        selector = selector == undefined ? '#proud-search-autocomplete' : selector;
        $.ajax({
          url: settings.proud_search.endpoint,
          data: {query: value},
          success: function(data) {
            console.log(data);
            $wrapper = $(selector);
            $wrapper.html('');
            if (data.list.length) {
              $.each(data.list, function( index, item ) {
                if (index < settings.proud_search.max_results) {
                  var icon = settings.proud_search.icons[item.type];
                  var $item = $('<li>');
                  $('<a>').html('<i class="fa '+ icon +'"></i> ' + item.title).attr('href', item.url).bind('click', function(e) {
                    //if (settings.proud_search.311_types.indexOf(item.type) != -1){
                      switch (item.type) {
                        case 'faq':
                          window.location.hash = '';
                          break;
                        case '':
                          window.location.hash = 'payment/' + item.nid;
                          break;
                      }
                      e.preventDefault();
                    //}
                  }).prependTo($item);
                }
                $item.appendTo($wrapper);

              });
            }
            else {
              $('<span>').html('Click <i class="fa fa-search fa-fw"></i> to search our site with Google').appendTo($wrapper);
            }
          }
        });
        
      }

      var options = {
        callback: proud_autocomplete,
        wait: 250,
        highlight: true,
        captureLength: 2
      }

      $("#proud-search-input").typeWatch( options );



      $('body').on('proudNavClick', function(event) {
        switch(event['event']) {
          case 'search':
            if(settings.proud_search.render_in_overlay) {
              event.callback(null, false, 'search-id');
            }
            else {
              event.callback(null, true);
            }
            break;
        }
      });

    }
  };
})(jQuery, Drupal);
