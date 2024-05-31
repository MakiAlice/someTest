import { _decorator, Component, Node, Button, input, Input, director, EventTouch, view, ResolutionPolicy } from 'cc';
const { ccclass, property } = _decorator;

@ccclass('start')
export class start extends Component {
    @property(Node)buttonS:Node
    start() {
    this.buttonS.on(Input.EventType.TOUCH_START,(event:EventTouch)=>{
        this.buttonS.setScale(0.9,0.9);
    },this);
    this.buttonS.on(Input.EventType.TOUCH_END,this.onTouch,this);
    view.setDesignResolutionSize(1280,720,ResolutionPolicy.EXACT_FIT);
    }
   

    onTouch(){
        //开始游戏
        this.buttonS.setScale(1,1);
        director.loadScene("stage");
    }

    update(deltaTime: number) {
        
    }
}


