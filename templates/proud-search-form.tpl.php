<form class="form-inline get-started search-form align-left" id="wrapper-search" style="margin-top:30px" action="<?php print $action; ?>">

<div class="input-group">
  <input 
    id="proud-search-input" class="form-control input-lg" type="text" autocomplete="off"
    placeholder="<?php print $placeholder; ?>" 
    name="<?php print $name; ?>" 
    value="<?php print $query; ?>"
  >
  <span class="input-group-btn">
    <button type="submit" value="Go" class="btn btn-primary btn-lg" id="proud-search-submit"><i class="fa fa-search"></i></button>
  </span>
</div>
<ul id="proud-search-autocomplete" class="search-autosuggest"></ul>
</form>