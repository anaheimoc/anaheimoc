<?php
// $Id: node.tpl.php,v 1.1.2.3 2010/01/11 00:08:12 sociotech Exp $
?>

<div id="node-<?php print $node->nid; ?>" class="node <?php print $node_classes; ?> <?php print 'web-package-' . $variables['field_mem_web_package'][0]['safe']; ?>">
  <div class="inner">
    <?php print $picture ?>

    <?php if ($page == 0): ?>
    <h2 class=""><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
    <?php endif; ?>

    <?php if ($submitted): ?>
    <div class="meta">
      <span class="submitted"><?php print $submitted ?></span>
    </div>
    <?php endif; ?>

    <?php if ($node_top && !$teaser): ?>
    <div id="node-top" class="node-top row nested">
      <div id="node-top-inner" class="node-top-inner inner">
        <?php print $node_top; ?>
      </div><!-- /node-top-inner -->
    </div><!-- /node-top -->
    <?php endif; ?>
    
    <?php if ($variables['field_mem_internet_reservationur'][0]['url']): ?>
    <div class="partner-book-now">
      <?php print $book_now; ?>
    </div>
    <?php endif; ?>
    
    <div class="partner-listing-top">
    	 
    	 <div class="logo-contact-wrapper">
	    	 <div class="partner-logo">
	    	   <?php print $partner_logo; ?>
	    	   <?php print $partner_address; ?>
	    	   <div class="video_tour"><?php print $video_tour; ?></div>    	   
	    	 </div>
	    	 
	    	 <div class="partner-contact-info">
	    	   <h3>Contact</h3>
		    	 <div><?php print $partner_phone; ?></div>
		    	 <div><?php print $partner_fax; ?></div>
		    	 <div><?php print $partner_tollfree; ?></div>
		    	 <div><?php print $partner_website; ?></div>
	    	 </div>
	    	 
	    	 <div class="coupon-offer-teaser">
	    	   <?php print $coupon_offer; ?>
	    	 </div>
    	 </div> <!-- / End of Logo/Contact Wrapper -->
    	 
    	 <div class="partner-image-teaser-wrapper">
    	   <h3><a href="<?php print $variables['node_url'] . '/?quicktabs_1=3#quicktabs-1' ; ?>">Photos</a></h3>
    	   <?php print $partner_image_teaser; ?>
    	 </div>
    	 
    	 <div class="partner-map-teaser-wrapper">
    	   <h3>Map</h3>
    	   <?php print $map_teaser; ?>
    	 </div>

    </div> <!-- / End of Partner Listing Top Section -->

    <div class="content clearfix">
            
    </div>

    <?php if ($links): ?>
    <div class="links">
      <?php print $links; ?>
    </div>
    <?php endif; ?>
  </div><!-- /inner -->

  <?php if ($node_bottom && !$teaser): ?>
  <div id="node-bottom" class="node-bottom row nested">
    <div id="node-bottom-inner" class="node-bottom-inner inner">
      <?php print $node_bottom; ?>
    </div><!-- /node-bottom-inner -->
  </div><!-- /node-bottom -->
  <?php endif; ?>
</div><!-- /node-<?php print $node->nid; ?> -->
