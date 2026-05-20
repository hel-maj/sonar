/* ===== 23e812d00 workers.fishing.memory_reeling:MemoryReelingTracker._pattern_scan ===== */
/* ghidra_name=FUN_23e812d00 entry=23e812d00 size=2305 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e812d00(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  undefined8 uVar7;
  code *pcVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong lVar15;
  undefined4 uVar16;
  longlong *plVar17;
  longlong *local_68;
  longlong *plStack_60;
  longlong *local_58;
  
  plVar10 = _DAT_23eede850;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eede850 == (longlong *)0x0) {
LAB_23e812d3e:
    _DAT_23eede850 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede980,DAT_23eedd0f8,0x20);
  }
  else {
    lVar15 = *_DAT_23eede850;
    if (1 < lVar15) {
      *_DAT_23eede850 = lVar15 + -1;
      goto LAB_23e812d3e;
    }
    if (_DAT_23eede850[2] != 0) {
      *_DAT_23eede850 = lVar15 + -1;
      if (lVar15 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e812d3e;
    }
  }
  plVar4 = _DAT_23eede850;
  lVar15 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eede850 + 9;
  lVar3 = *(longlong *)(lVar15 + 8);
  _DAT_23eede850[0xf] = lVar3;
  *(longlong **)(lVar15 + 8) = plVar10;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar7 = _DAT_23eedd528;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,uVar7);
  if (plVar10 == (longlong *)0x0) {
    plVar11 = *(longlong **)(param_1 + 0x60);
    plVar13 = *(longlong **)(param_1 + 0x70);
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar12 = (longlong *)0x0;
    uVar16 = 0x185;
    plVar6 = *(longlong **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = DAT_23ed6a4f8;
  }
  else {
    plVar11 = (longlong *)FUN_23e8bf9b0(plVar2,DAT_23eedd578);
    if (plVar11 == (longlong *)0x0) {
      plVar11 = *(longlong **)(param_1 + 0x60);
      plVar13 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar6 = *(longlong **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar10 = *plVar10 + -1;
      plVar14 = (longlong *)0x0;
      if (*plVar10 == 0) {
        plVar12 = (longlong *)0x0;
        (**(code **)(plVar10[1] + 0x30))(plVar10);
        uVar16 = 0x185;
        plVar10 = DAT_23ed6a4f8;
      }
      else {
        plVar12 = (longlong *)0x0;
        uVar16 = 0x185;
        plVar10 = DAT_23ed6a4f8;
      }
    }
    else {
      *(undefined4 *)(plVar4 + 5) = 0x185;
      plVar12 = (longlong *)FUN_23e914090(param_1,plVar10,plVar11);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (plVar12 == (longlong *)0x0) {
        plVar11 = *(longlong **)(param_1 + 0x60);
        plVar13 = *(longlong **)(param_1 + 0x70);
        plVar14 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar16 = 0x185;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar10 = DAT_23ed6a4f8;
        plVar6 = *(longlong **)(param_1 + 0x68);
      }
      else {
        *(undefined4 *)(plVar4 + 5) = 0x186;
        plVar10 = (longlong *)FUN_23e915840(param_1,plVar1,_DAT_23eedd530,plVar12);
        if (plVar10 == (longlong *)0x0) {
          plVar11 = *(longlong **)(param_1 + 0x60);
          plVar13 = *(longlong **)(param_1 + 0x70);
          uVar16 = 0x186;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar6 = *(longlong **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar14 = (longlong *)0x0;
          plVar10 = DAT_23ed6a4f8;
        }
        else {
          iVar9 = FUN_23a35f020(plVar10);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          plVar10 = DAT_23ed6ccf0;
          if (iVar9 == -1) {
            plVar11 = *(longlong **)(param_1 + 0x60);
            plVar13 = *(longlong **)(param_1 + 0x70);
            plVar14 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar16 = 0x186;
            plVar6 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar10 = DAT_23ed6a4f8;
          }
          else {
            if (iVar9 == 0) {
              plVar14 = (longlong *)0x0;
              *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
              goto LAB_23e812e9b;
            }
            plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedd378);
            if (plVar10 == (longlong *)0x0) {
              plVar11 = *(longlong **)(param_1 + 0x60);
              plVar13 = *(longlong **)(param_1 + 0x70);
              plVar14 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar16 = 0x188;
              plVar6 = *(longlong **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar10 = DAT_23ed6a4f8;
            }
            else {
              plVar13 = (longlong *)FUN_23e8bf9b0(plVar12,_DAT_23eedd580);
              plVar11 = _DAT_23eedd3a0;
              if (plVar13 == (longlong *)0x0) {
                plVar11 = *(longlong **)(param_1 + 0x60);
                plVar13 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                plVar6 = *(longlong **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  plVar14 = (longlong *)0x0;
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                  uVar16 = 0x188;
                  plVar10 = DAT_23ed6a4f8;
                }
                else {
                  plVar14 = (longlong *)0x0;
                  uVar16 = 0x188;
                  plVar10 = DAT_23ed6a4f8;
                }
              }
              else {
                *(undefined4 *)(plVar4 + 5) = 0x188;
                plStack_60 = plVar11;
                local_68 = plVar13;
                plVar14 = (longlong *)FUN_23e94ed00(param_1,plVar10,&local_68);
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                if (plVar14 == (longlong *)0x0) {
                  plVar11 = *(longlong **)(param_1 + 0x60);
                  plVar13 = *(longlong **)(param_1 + 0x70);
                  uVar16 = 0x188;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  plVar6 = *(longlong **)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar10 = DAT_23ed6a4f8;
                }
                else {
                  plVar10 = (longlong *)FUN_23e8bd600(param_1,plVar14);
                  if (plVar10 == (longlong *)0x0) {
                    plVar11 = *(longlong **)(param_1 + 0x60);
                    plVar13 = *(longlong **)(param_1 + 0x70);
                    uVar16 = 0x189;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plVar6 = *(longlong **)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plVar10 = DAT_23ed6a4f8;
                  }
                  else {
                    lVar15 = *plVar10 + -1;
                    if ((plVar10[2] != 1) || ((int)plVar10[3] != 4)) {
                      *plVar10 = lVar15;
                      if (lVar15 == 0) {
                        (**(code **)(plVar10[1] + 0x30))();
                      }
                      plVar10 = DAT_23ed6ccf0;
                      *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
LAB_23e812e9b:
                      lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                      plVar4 = *(longlong **)(lVar15 + 0x28);
                      plVar11 = (longlong *)plVar4[2];
                      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                           *(undefined8 *)(lVar15 + 0x30);
                      *(undefined4 *)(plVar4 + 8) = 0xffffffff;
                      if (plVar11 != (longlong *)0x0) {
                        plVar4[2] = 0;
                        *plVar11 = *plVar11 + -1;
                        if (*plVar11 == 0) {
                          (**(code **)(plVar11[1] + 0x30))();
                        }
                      }
                      *plVar4 = *plVar4 + -1;
                      if (*plVar4 == 0) {
                        (**(code **)(plVar4[1] + 0x30))(plVar4);
                      }
                      plVar4[0xf] = 0;
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        (**(code **)(plVar12[1] + 0x30))(plVar12);
                      }
                      if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0))
                      {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      *plVar1 = *plVar1 + -1;
                      if (*plVar1 == 0) {
                        (**(code **)(plVar1[1] + 0x30))(plVar1);
                      }
                      *plVar2 = *plVar2 + -1;
                      if (*plVar2 != 0) {
                        return plVar10;
                      }
                      (**(code **)(plVar2[1] + 0x30))(plVar2);
                      return plVar10;
                    }
                    *plVar10 = lVar15;
                    if (lVar15 == 0) {
                      (**(code **)(plVar10[1] + 0x30))();
                    }
                    lVar15 = FUN_23e8dc840();
                    plVar10 = _DAT_23eedd588;
                    if (lVar15 == 0) {
                      FUN_23e915740(param_1,&local_68,_DAT_23eedd388);
                      uVar16 = 0x18b;
                      plVar13 = local_58;
                      plVar10 = DAT_23ed6a4f8;
                      plVar11 = local_68;
                      plVar6 = plStack_60;
                    }
                    else {
                      *(undefined4 *)(plVar4 + 5) = 0x18b;
                      local_68 = plVar10;
                      plStack_60 = plVar14;
                      plVar11 = (longlong *)FUN_23e954670(param_1,lVar15,_DAT_23eedd390,&local_68);
                      if (plVar11 != (longlong *)0x0) {
                        plVar10 = (longlong *)FUN_23a388650(param_1,plVar11,DAT_23ed6ccf0,0);
                        *plVar11 = *plVar11 + -1;
                        if (*plVar11 == 0) {
                          (**(code **)(plVar11[1] + 0x30))(plVar11);
                        }
                        if (plVar10 != (longlong *)0x0) goto LAB_23e812e9b;
                      }
                      plVar11 = *(longlong **)(param_1 + 0x60);
                      plVar13 = *(longlong **)(param_1 + 0x70);
                      uVar16 = 0x18b;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar10 = DAT_23ed6a4f8;
                      plVar6 = *(longlong **)(param_1 + 0x68);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  DAT_23ed6a4f8 = plVar10;
  if (plVar13 == (longlong *)0x0) {
    if (plVar10 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar10;
      *plVar10 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar8 = _PyRuntime_exref;
    plVar10[2] = 0;
    plVar10[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar15 = *(longlong *)(pcVar8 + 0x1f8);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar16;
    lVar15 = *(longlong *)(lVar15 + 0x10);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar15 = *(longlong *)(lVar15 + 0x2e8);
    lVar3 = plVar10[-1];
    puVar5 = *(undefined8 **)(lVar15 + 8);
    *puVar5 = plVar10 + -2;
    plVar10[-2] = lVar15;
    plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar15 + 8) = plVar10 + -2;
    plVar17 = plVar10;
  }
  else {
    plVar17 = plVar13;
    if ((longlong *)plVar13[3] != plVar4) {
      if (plVar10 == (longlong *)0x0) {
        plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar10;
        *plVar10 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar10[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      *(undefined4 *)((longlong)plVar10 + 0x24) = uVar16;
      pcVar8 = _PyRuntime_exref;
      *(undefined4 *)(plVar10 + 4) = 0xffffffff;
      lVar15 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar8 + 0x1f8) + 0x10) + 0x2e8);
      lVar3 = plVar10[-1];
      puVar5 = *(undefined8 **)(lVar15 + 8);
      *puVar5 = plVar10 + -2;
      plVar10[-2] = lVar15;
      plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *plVar13;
      *(longlong **)(lVar15 + 8) = plVar10 + -2;
      plVar10[2] = (longlong)plVar13;
      plVar17 = plVar10;
      if (lVar3 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5e2ee,plVar1,plVar2,plVar12,plVar14);
  if (_DAT_23eede850 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eede850 = (longlong *)0x0;
  }
  lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar15 + 0x28);
  plVar4 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
  *(undefined4 *)(plVar10 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar10[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  plVar10[0xf] = 0;
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,plVar11,plVar6,plVar17);
  return (longlong *)0x0;
}
