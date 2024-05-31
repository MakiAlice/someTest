import { _decorator, Component, Node, Animation, Graphics, animation, AnimationState, SkeletalAnimationState, Prefab, instantiate, TiledObjectGroup, Sprite, ProgressBar, Input, Label } from 'cc';
const { ccclass, property } = _decorator;

@ccclass('map')
export class map extends Component {
    @property(Node)road:Node;
    @property(Prefab)enemy:Prefab;
    @property(Node)enemys:Node;
    @property(Node)coin:Node;
    Prenode=new Node;
    flag=1;
    i=[];
    pre=0;
    start() {
        const ani=this.road.getComponent(Animation);
        ani.play();
        this.i[0]=0;
        this.Prenode.setPosition(this.road.getPosition());
        this.schedule(this.enemyMake,2,4);
    }


    enemyMove(j){
            //通过数组i[]使得每一个enemy单独行走
            if(this.enemys.children[j].isValid==true  && this.i[j]<this.road.children.length-1) {
                this.i[j]++;
                const l=this.road.children[this.i[j]].getPosition();
                this.enemys.children[j].setPosition(l);
            }
            
        
    }

    enemyMake(){
        this.enemys.addChild(instantiate(this.enemy));
        this.pre=this.pre+1;
        this.i[this.pre]=0;
    }

    enemyCheck(){
        for(let i=0;i<this.enemys.children.length;i++){
            if(this.enemys.children[i].isValid==true  && this.enemys.children[i].children[0].children[0].getComponent(Sprite).fillRange<=0){
                this.enemys.children[i].destroy();
                for(let i=0;i<this.i.length-1;i++){
                    this.i[i]=this.i[i+1];
                }
                this.i[this.i.length-1]=0;
                let l=parseInt(this.coin.getComponent(Label).string);
                l+=5;
                this.coin.getComponent(Label).string=l.toString();
            }
        }
    }

    getL(){
        //跑road动画绘制点，让enemy根据这些点调整坐标形成按轨迹行走
        if(this.flag==1){
            let newNode=new Node;
            let x=this.road.getPosition();
            newNode.setPosition(x);
            if(this.Prenode.getPosition()!=x){
                this.road.addChild(newNode);
                this.Prenode.setPosition(x);
            }
        }
    }

    update(deltaTime: number) {
        this.getL();
        const ani=this.road.getComponent(Animation);
        ani.on(Animation.EventType.FINISHED,()=>{this.flag=0;},this);//暂停新的点生成
        for(let i=0;i<this.enemys.children.length;i++){
            if(this.enemys.children[i].isValid==true)
            {this.enemyMove(i);}
        }
        this.enemyCheck();
    }
}


