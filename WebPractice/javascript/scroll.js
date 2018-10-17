// 单屏滚动 onepage_scroll
// pageScroll();
var myFullPage;
// function pageScroll(data) {
    myFullPage = new FullPage({
      id : 'fullpage',                            // id of contain
      slideTime : 1000,                               // time of slide
        effect : {                                     // slide effect
            transform : {
              translate : 'Y',             // 'X'|'Y'|'XY'|'none'
              scale : [0, 1],            // [scalefrom, scaleto]
              rotate : [0, 0]            // [rotatefrom, rotateto]
            },
            opacity : [0, 1]                           // [opacityfrom, opacityto]
        },                           
      mode : 'touch,wheel',               // mode of fullpage
      easing : [0, .93, .39, .98],

    });

    // $('.container-fluid').fullpage({
    //   sectionsColor: ['#ffffff', '#5FD2ED', '#EA9F96', '#83A9ED', '#D190D1','#81C5F7','#F7B052','#727AD6','#39b54a','#0686D8'],
    //   afterLoad:function(anchorLink,index){
    //     console.log(`当前是${index}页`);
    //   },
    //   easingcss3: 'cubic-bezier(0.175, 0.185, 0.320, 1.275)'

    // });
    console.log(11);
    var mySwiper = new Swiper('.swiper-container', {
        loop: true,
        grabCursor: true,
        paginationClickable: true
    })
    $('.arrow-left').on('click', function(e) {
        e.preventDefault();
        mySwiper.swipePrev();
    })
    $('.arrow-right').on('click', function(e) {
        e.preventDefault();
        mySwiper.swipeNext();
    });
    // parts-9
// }
