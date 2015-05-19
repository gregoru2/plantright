/**
 * Used on the nursery retailers page /nursery-partners
 */
 
 
 Drupal.behaviors.plantright_business_directory = function (context) {
	var $view = $('div.view-business-directory', context);
	if (!$view || $view.length === 0) {
		// Act only on the business directory view.
		return;
	}
	
	function array_unique(arr) {
		var ret = [arr[0]];
		for (var i = 1; i < arr.length; i++) { // start loop at 1 as element 0 can never be a duplicate
			if ($.inArray(arr[i], ret) === -1) {
				ret.push(arr[i]);
			}
		}
		return ret;
	}
	
	/**
	 * @method processLocations
	 * @param {jquery object} $locations jquery nodes for all the locations in the 
	 * @param {String} locationsInName Name for where the locations are in for "locations in XYZ"
	 * @param {Boolean} groupByCounty Whether to group the retailer locations by county and show the county name
	 * view or subset of the view.
	 */
	function processLocations($locations, locationsInName, groupByCounty) {
		var retailerIds = array_unique($('span.retailer-id', $locations).map(function() {
			return $(this).attr('data-retailer-id');
		}));
	
		$.each(retailerIds, function(index, value) {
			// Get the locations.
			var $retailerLocations = $('[data-retailer-id=' + value + ']', $locations);
			var locationCount = $retailerLocations.length;
			if ($retailerLocations.length > 1) {
				$retailerLocations = $retailerLocations.closest('.views-row');
				// Create a new location container.
				// Remove the locations put them into element on the first
				var $firstLocation = $retailerLocations.eq(0);
				var $newLocationNode = $firstLocation.clone();
				$newLocationNode.find('.views-field-address').remove();
				$firstLocation.before($newLocationNode);
				
				if (true === groupByCounty) {
					// Get counties list.
					var counties = array_unique($('span.retailer-county', $retailerLocations).map(function() {
						return $.trim($(this).attr('data-retailer-county'));
					})).sort();
					
					if (counties.length > 1) {
						var $retailerLocationsByCounty = $('<div>');
						var $locationsByCounty = $.each(counties, function(index, county) {
							$retailerLocationsByCounty.append($('<h4>' + county + ' County' + '</h4>'));
							var $countyLocations = $('[data-retailer-county=' + county + ']', $retailerLocations).closest('.views-row');
							$retailerLocationsByCounty.append($countyLocations);
						});
						
						$retailerLocations = $retailerLocationsByCounty.children();
					}
				}
				
				$retailerLocations.each(function() {
					if (!$(this).hasClass('views-row')) {return;}
					$(this).removeClass()
					.addClass('retailer-location')
					.find('>div:not(.views-field-address)').remove();
				});
				
				var $locationsContainer = $('<div class="multi-locations-container"><div class="prompt"></div><div class="retailer-locations"></div></div>');
				$locationsContainer.find('.retailer-locations').append($retailerLocations);
				$locationsContainer.find('.prompt').html('<p class="location-count">' + locationCount + ' locations in ' + locationsInName + '</p>' +
				'<div class="location-toggle"><a href="javascript:void(0)"><span class="open-locations">See all locations</span><span class="close-locations">Close locations list</span></div></a>');
				$locationsContainer.find('.location-toggle a').bind('click', function(e) {
					e.preventDefault();
					$locationsContainer.find('.retailer-locations').slideToggle();
					$locationsContainer.find('.close-locations, .open-locations').toggle();
				});

				$locationsContainer.find('.retailer-locations, .close-locations').hide();
				
				$newLocationNode.append($locationsContainer);
			}
		});
	}
	
	//view-display-id-page_1: default (all counties, grouped by county)
	//view-display-id-page_2: by zip (sorted by distance) -- no grouping
	//view-display-id-page_3: by alphabetical name
	//view-display-id-page_4: by county (single county)
	
	// Remove class names, because they don't have any use
	// when we're moving the rows around to group them by retailer.
        $view.hide();
        $view.before('<div id="business-dir-loading"><img src="/sites/all/themes/pr11/drupal/throbber.gif"></div>');
        
	$view.find('.views-row').removeClass('views-row-odd views-row-even views-row-first views-row-last');

	if ($view.hasClass('view-display-id-page_1')) {
		$('div.view-content h3', $view).each(function() {
			// this: county div.
			
			// Get all the locations for the county.
			//$(this).nextUntil('h3'); doesn't work until jquery 1.4
			var h3Index = null;
			var $locationsByCounty = $(this).nextAll().filter(function(index) {
				// Stop at h3
				if (h3Index !== null || $(this).is('h3')) {
					h3Index = index;
					return false;
				}
				else {
					return true;
				}
			});
			
			// See how many of the same retailer are in the county.
			processLocations($locationsByCounty, $(this).text() + ' County');
		});
	}
	else if ($view.hasClass('view-display-id-page_3')) {
		processLocations($view.find('div.view-content div.views-row'), 'California', true);
	}
	else if ($view.hasClass('view-display-id-page_4')) {
		var title = $('.block-plantright_business_directory h2').text();
		var county = title.replace('Nurseries in ', '');
		processLocations($view.find('div.view-content div.views-row'), county + ' County');
	}

	$('#business-dir-loading', context).remove();
        $view.show();
};