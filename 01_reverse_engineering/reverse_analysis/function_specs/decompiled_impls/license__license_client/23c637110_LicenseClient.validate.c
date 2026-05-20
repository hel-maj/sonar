/* ===== 23c637110 license.license_client:392 ===== */
/* ghidra_name=FUN_23c637110 entry=23c637110 size=1981 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23c637110(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  code *pcVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *plVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar7 = _DAT_23ee29c50;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23ee29c50 == (longlong *)0x0) {
LAB_23c63714a:
    _DAT_23ee29c50 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ee29c48,DAT_23ee29d18,8);
  }
  else {
    lVar2 = *_DAT_23ee29c50;
    if (1 < lVar2) {
      *_DAT_23ee29c50 = lVar2 + -1;
      goto LAB_23c63714a;
    }
    if (_DAT_23ee29c50[2] != 0) {
      *_DAT_23ee29c50 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23c63714a;
    }
  }
  plVar3 = _DAT_23ee29c50;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar7 = _DAT_23ee29c50 + 9;
  lVar9 = *(longlong *)(lVar2 + 8);
  _DAT_23ee29c50[0xf] = lVar9;
  *(longlong **)(lVar2 + 8) = plVar7;
  if ((lVar9 != 0) &&
     (((*(char *)(lVar9 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar9 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar9 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar9 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar9 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar11 = _DAT_23ee283b8;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,uVar11);
  if (plVar7 != (longlong *)0x0) {
    iVar6 = FUN_23a35f020(plVar7);
    lVar2 = *plVar7 + -1;
    if (iVar6 == -1) {
      uVar11 = *(undefined8 *)(param_1 + 0x60);
      uVar12 = *(undefined8 *)(param_1 + 0x68);
      uVar13 = 0x18a;
      plVar10 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar7 = lVar2;
      if (lVar2 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23c637502;
    }
    *plVar7 = lVar2;
    if (lVar2 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    if (iVar6 == 0) {
LAB_23c637219:
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar7 = *(longlong **)(lVar2 + 0x28);
      plVar3 = (longlong *)plVar7[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
      *(undefined4 *)(plVar7 + 8) = 0xffffffff;
      if (plVar3 != (longlong *)0x0) {
        plVar7[2] = 0;
        *plVar3 = *plVar3 + -1;
        if (*plVar3 == 0) {
          (**(code **)(plVar3[1] + 0x30))();
        }
      }
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      plVar7[0xf] = 0;
      pcVar5 = _Py_NoneStruct_exref;
      *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
      *plVar1 = *plVar1 + -1;
      if (*plVar1 != 0) {
        return pcVar5;
      }
      (**(code **)(plVar1[1] + 0x30))(plVar1);
      return pcVar5;
    }
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23ee283b8);
    if (plVar7 != (longlong *)0x0) {
      *(undefined4 *)(plVar3 + 5) = 0x18a;
      plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar7,_DAT_23ee288b8);
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      if (plVar8 != (longlong *)0x0) {
        iVar6 = FUN_23a35f020(plVar8);
        lVar2 = *plVar8 + -1;
        if (iVar6 == -1) {
          uVar11 = *(undefined8 *)(param_1 + 0x60);
          uVar12 = *(undefined8 *)(param_1 + 0x68);
          plVar10 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar8 = lVar2;
          if (lVar2 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          uVar13 = 0x18a;
        }
        else {
          *plVar8 = lVar2;
          if (lVar2 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          if (iVar6 != 1) goto LAB_23c637219;
          lVar9 = FUN_23ead5f40();
          lVar2 = _DAT_23ee28918;
          if (lVar9 == 0) {
            uVar13 = 0x18b;
            FUN_23e915740(param_1,&uStack_68,DAT_23ee283f8);
            uVar11 = uStack_68;
            uVar12 = uStack_60;
            plVar10 = plStack_58;
          }
          else {
            *(undefined4 *)(plVar3 + 5) = 0x18b;
            plVar7 = (longlong *)
                     FUN_23e915840(param_1,lVar9,DAT_23ee28400,*(undefined8 *)(lVar2 + 0x18));
            if (plVar7 == (longlong *)0x0) {
              uVar11 = *(undefined8 *)(param_1 + 0x60);
              uVar13 = 0x18b;
              plVar10 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar12 = *(undefined8 *)(param_1 + 0x68);
            }
            else {
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23ee283d0);
              if (plVar7 != (longlong *)0x0) {
                *(undefined4 *)(plVar3 + 5) = 0x18c;
                plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar7,_DAT_23ee28920);
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                }
                if (plVar10 != (longlong *)0x0) {
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23ee283b8);
                  if (plVar7 != (longlong *)0x0) {
                    plVar10 = (longlong *)FUN_23e8bc2f0(plVar7,_DAT_23ee28928);
                    *plVar7 = *plVar7 + -1;
                    if (*plVar7 == 0) {
                      (**(code **)(plVar7[1] + 0x30))(plVar7);
                    }
                    lVar2 = _DAT_23ee28930;
                    if (plVar10 != (longlong *)0x0) {
                      *(undefined4 *)(plVar3 + 5) = 0x18d;
                      plVar7 = (longlong *)
                               FUN_23e9186b0(param_1,plVar10,lVar2 + 0x18,_DAT_23ee28938);
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                      }
                      if (plVar7 != (longlong *)0x0) {
                        *plVar7 = *plVar7 + -1;
                        if (*plVar7 == 0) {
                          (**(code **)(plVar7[1] + 0x30))(plVar7);
                        }
                        lVar9 = FUN_23ead5f40();
                        lVar2 = _DAT_23ee28940;
                        if (lVar9 == 0) {
                          uVar13 = 0x18e;
                          FUN_23e915740(param_1,&uStack_68,DAT_23ee283f8);
                          uVar11 = uStack_68;
                          uVar12 = uStack_60;
                          plVar10 = plStack_58;
                        }
                        else {
                          *(undefined4 *)(plVar3 + 5) = 0x18e;
                          plVar7 = (longlong *)
                                   FUN_23e915840(param_1,lVar9,DAT_23ee28400,
                                                 *(undefined8 *)(lVar2 + 0x18));
                          if (plVar7 != (longlong *)0x0) {
                            *plVar7 = *plVar7 + -1;
                            if (*plVar7 == 0) {
                              (**(code **)(plVar7[1] + 0x30))(plVar7);
                            }
                            goto LAB_23c637219;
                          }
                          uVar11 = *(undefined8 *)(param_1 + 0x60);
                          uVar13 = 0x18e;
                          plVar10 = *(longlong **)(param_1 + 0x70);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          uVar12 = *(undefined8 *)(param_1 + 0x68);
                        }
                        goto LAB_23c637502;
                      }
                    }
                  }
                  uVar11 = *(undefined8 *)(param_1 + 0x60);
                  uVar13 = 0x18d;
                  plVar10 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar12 = *(undefined8 *)(param_1 + 0x68);
                  goto LAB_23c637502;
                }
              }
              uVar11 = *(undefined8 *)(param_1 + 0x60);
              uVar13 = 0x18c;
              plVar10 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar12 = *(undefined8 *)(param_1 + 0x68);
            }
          }
        }
        goto LAB_23c637502;
      }
    }
  }
  plVar10 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar13 = 0x18a;
  uVar11 = *(undefined8 *)(param_1 + 0x60);
  uVar12 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23c637502:
  plVar7 = DAT_23ed6a4f8;
  if (plVar10 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar7 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar10 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar10;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar5 = _PyRuntime_exref;
    plVar7[2] = 0;
    plVar7[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar2 = *(longlong *)(pcVar5 + 0x1f8);
    *(undefined4 *)(plVar7 + 4) = 0xffffffff;
    lVar2 = *(longlong *)(lVar2 + 0x10);
    *(undefined4 *)((longlong)plVar7 + 0x24) = uVar13;
    lVar2 = *(longlong *)(lVar2 + 0x2e8);
    lVar9 = plVar7[-1];
    puVar4 = *(undefined8 **)(lVar2 + 8);
    *puVar4 = plVar7 + -2;
    plVar7[-2] = lVar2;
    plVar7[-1] = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar2 + 8) = plVar7 + -2;
    plVar8 = plVar7;
  }
  else {
    plVar8 = plVar10;
    if ((longlong *)plVar10[3] != plVar3) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar7 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar8 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar8;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar5 = _PyRuntime_exref;
      plVar7[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      lVar2 = *(longlong *)(pcVar5 + 0x1f8);
      *(undefined4 *)(plVar7 + 4) = 0xffffffff;
      *(undefined4 *)((longlong)plVar7 + 0x24) = uVar13;
      lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x2e8);
      lVar9 = plVar7[-1];
      puVar4 = *(undefined8 **)(lVar2 + 8);
      *puVar4 = plVar7 + -2;
      plVar7[-2] = lVar2;
      plVar7[-1] = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar4;
      lVar9 = *plVar10;
      *(longlong **)(lVar2 + 8) = plVar7 + -2;
      plVar7[2] = (longlong)plVar10;
      plVar8 = plVar7;
      if (lVar9 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
  }
  FUN_23e8bba40(plVar3,&DAT_23ec47964,plVar1);
  if (_DAT_23ee29c50 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23ee29c50 = (longlong *)0x0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar2 + 0x28);
  plVar3 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
  *(undefined4 *)(plVar7 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar7[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  plVar7[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar11,uVar12,plVar8);
  return (code *)0x0;
}
