/* ===== 23e11b460 telegram.handlers.menu_handler:17 ===== */
/* ghidra_name=FUN_23e11b460 entry=23e11b460 size=1688 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_23e11b460(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  code *pcVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined4 uVar12;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar9 = _DAT_23eeab098;
  if (_DAT_23eeab098 == (longlong *)0x0) {
LAB_23e11b497:
    _DAT_23eeab098 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeab090,DAT_23eeab0a8,8);
  }
  else {
    lVar7 = *_DAT_23eeab098;
    if (1 < lVar7) {
      *_DAT_23eeab098 = lVar7 + -1;
      goto LAB_23e11b497;
    }
    if (_DAT_23eeab098[2] != 0) {
      *_DAT_23eeab098 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e11b497;
    }
  }
  plVar2 = _DAT_23eeab098;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eeab098 + 9;
  lVar1 = *(longlong *)(lVar7 + 8);
  _DAT_23eeab098[0xf] = lVar1;
  *(longlong **)(lVar7 + 8) = plVar9;
  if ((lVar1 != 0) &&
     (((*(char *)(lVar1 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar1 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar1 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar1 + 0x38))
       ) && (plVar2[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar1 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  *(undefined4 *)(plVar2 + 8) = 0;
  lVar7 = FUN_23e900830();
  if (lVar7 == 0) {
    uVar12 = 0x13;
    FUN_23e915740(param_1,&uStack_68,_DAT_23eea8e68);
    plVar8 = (longlong *)0x0;
    plVar9 = plStack_58;
    uVar4 = uStack_68;
    uVar5 = uStack_60;
    plVar10 = DAT_23ed6a4f8;
  }
  else {
    *(undefined4 *)(plVar2 + 5) = 0x13;
    plVar8 = (longlong *)FUN_23e91a870(param_1,lVar7);
    if (plVar8 == (longlong *)0x0) {
      uVar4 = *(undefined8 *)(param_1 + 0x60);
      uVar12 = 0x13;
      plVar9 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar5 = *(undefined8 *)(param_1 + 0x68);
      plVar10 = DAT_23ed6a4f8;
    }
    else {
      plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eea8e70);
      lVar7 = _DAT_23eea8e78;
      if (plVar9 != (longlong *)0x0) {
        *(undefined4 *)(plVar2 + 5) = 0x14;
        plVar10 = (longlong *)FUN_23e9186b0(param_1,plVar9,lVar7 + 0x18,_DAT_23eea8e80);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar10 != (longlong *)0x0) {
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eea8e70);
          lVar7 = _DAT_23eea8e88;
          if (plVar9 != (longlong *)0x0) {
            *(undefined4 *)(plVar2 + 5) = 0x15;
            plVar10 = (longlong *)FUN_23e9186b0(param_1,plVar9,lVar7 + 0x18,_DAT_23eea8e80);
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            if (plVar10 != (longlong *)0x0) {
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eea8e70);
              lVar7 = _DAT_23eea8e90;
              if (plVar9 != (longlong *)0x0) {
                *(undefined4 *)(plVar2 + 5) = 0x16;
                plVar10 = (longlong *)FUN_23e9186b0(param_1,plVar9,lVar7 + 0x18,_DAT_23eea8e80);
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                if (plVar10 != (longlong *)0x0) {
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  lVar7 = _DAT_23eea8ea0;
                  *(undefined4 *)(plVar2 + 5) = 0x17;
                  plVar9 = (longlong *)
                           FUN_23e915840(param_1,plVar8,_DAT_23eea8e98,*(undefined8 *)(lVar7 + 0x18)
                                        );
                  if (plVar9 == (longlong *)0x0) {
                    uVar4 = *(undefined8 *)(param_1 + 0x60);
                    uVar12 = 0x17;
                    plVar9 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar5 = *(undefined8 *)(param_1 + 0x68);
                    plVar10 = DAT_23ed6a4f8;
                  }
                  else {
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                    }
                    *(undefined4 *)(plVar2 + 5) = 0x18;
                    lVar7 = FUN_23e91bfe0(param_1,plVar8,_DAT_23eea8ea8);
                    if (lVar7 != 0) {
                      lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                      plVar9 = *(longlong **)(lVar1 + 0x28);
                      plVar2 = (longlong *)plVar9[2];
                      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                           *(undefined8 *)(lVar1 + 0x30);
                      *(undefined4 *)(plVar9 + 8) = 0xffffffff;
                      if (plVar2 != (longlong *)0x0) {
                        plVar9[2] = 0;
                        *plVar2 = *plVar2 + -1;
                        if (*plVar2 == 0) {
                          (**(code **)(plVar2[1] + 0x30))();
                        }
                      }
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        (**(code **)(plVar9[1] + 0x30))(plVar9);
                      }
                      plVar9[0xf] = 0;
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 != 0) {
                        return lVar7;
                      }
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                      return lVar7;
                    }
                    uVar4 = *(undefined8 *)(param_1 + 0x60);
                    uVar12 = 0x18;
                    plVar9 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar5 = *(undefined8 *)(param_1 + 0x68);
                    plVar10 = DAT_23ed6a4f8;
                  }
                  goto joined_r0x00023e11b7f5;
                }
              }
              uVar4 = *(undefined8 *)(param_1 + 0x60);
              uVar12 = 0x16;
              plVar9 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar5 = *(undefined8 *)(param_1 + 0x68);
              plVar10 = DAT_23ed6a4f8;
              goto joined_r0x00023e11b7f5;
            }
          }
          plVar9 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar12 = 0x15;
          uVar4 = *(undefined8 *)(param_1 + 0x60);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar5 = *(undefined8 *)(param_1 + 0x68);
          plVar10 = DAT_23ed6a4f8;
          goto joined_r0x00023e11b7f5;
        }
      }
      plVar9 = *(longlong **)(param_1 + 0x70);
      uVar4 = *(undefined8 *)(param_1 + 0x60);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar12 = 0x14;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar5 = *(undefined8 *)(param_1 + 0x68);
      plVar10 = DAT_23ed6a4f8;
    }
  }
joined_r0x00023e11b7f5:
  DAT_23ed6a4f8 = plVar10;
  if (plVar9 == (longlong *)0x0) {
    if (plVar10 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar10;
      *plVar10 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar11 = plVar10;
    }
    pcVar6 = _PyRuntime_exref;
    plVar11[2] = 0;
    plVar11[3] = (longlong)plVar2;
    *plVar2 = *plVar2 + 1;
    lVar7 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar12;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar1 = plVar11[-1];
    puVar3 = *(undefined8 **)(lVar7 + 8);
    *puVar3 = plVar11 + -2;
    plVar11[-2] = lVar7;
    plVar11[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar7 + 8) = plVar11 + -2;
  }
  else {
    plVar11 = plVar9;
    if ((longlong *)plVar9[3] != plVar2) {
      if (plVar10 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar10;
        *plVar10 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar11 = plVar10;
      }
      pcVar6 = _PyRuntime_exref;
      plVar11[3] = (longlong)plVar2;
      *plVar2 = *plVar2 + 1;
      lVar7 = *(longlong *)(pcVar6 + 0x1f8);
      *(undefined4 *)((longlong)plVar11 + 0x24) = uVar12;
      *(undefined4 *)(plVar11 + 4) = 0xffffffff;
      lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
      lVar1 = plVar11[-1];
      puVar3 = *(undefined8 **)(lVar7 + 8);
      *puVar3 = plVar11 + -2;
      plVar11[-2] = lVar7;
      plVar11[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
      lVar1 = *plVar9;
      *(longlong **)(lVar7 + 8) = plVar11 + -2;
      plVar11[2] = (longlong)plVar9;
      if (lVar1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
    }
  }
  FUN_23e8bba40(plVar2,&DAT_23ec5a08d,plVar8);
  if (_DAT_23eeab098 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23eeab098 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar7 + 0x28);
  plVar2 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar2 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar9[0xf] = 0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  FUN_23a33aa70(param_1,uVar4,uVar5,plVar11);
  return 0;
}
