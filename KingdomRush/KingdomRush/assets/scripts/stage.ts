import { _decorator, Component, Node, Prefab, Input, director, EventTouch, Vec3, game, SceneGlobals, instantiate, ResolutionPolicy, view } from 'cc';
const { ccclass, property } = _decorator;
import {data} from './data'
@ccclass('stage')
export class stage extends Component {
    @property(Node)stage:Node
    @property(Node)button:Node
    stagePos=[];

    start() {
    this.init();
    this.button.on(Input.EventType.TOUCH_END,()=>{
        director.loadScene('start');
    },this);
    view.setDesignResolutionSize(1280,720,ResolutionPolicy.EXACT_FIT);
    }

    init(){
        //读取stage点
        var root=director.getScene().getChildByName("data").getComponent(data);
        for(let i=0;i<this.stage.children.length;i++){
            const l=this.stage.children[i].position;
            this.stagePos[i]=l;
            if(i>0 && root.getData(i-1)==0){this.stage.children[i].active=false;}
            this.stage.children[i].on(Input.EventType.TOUCH_END,this.stageTouch,this);
        }
    }


    stageTouch(event:EventTouch){
        let touch=event.target;
        let s=-1;
        for(let i=0;i<this.stage.children.length;i++){
            if(touch==this.stage.children[i]){s=i;break;}
        }

        const l=`stage${s+1}`;
        director.loadScene(l);
    }

    update(deltaTime: number) {
    }

}


