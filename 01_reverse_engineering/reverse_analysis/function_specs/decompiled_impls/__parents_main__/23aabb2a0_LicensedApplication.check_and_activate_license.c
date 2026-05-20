/* ===== 23aabb2a0 __parents_main__:185 ===== */
/* ghidra_name=FUN_23aabb2a0 entry=23aabb2a0 size=4856 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23aabb2a0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong *plVar3;
  char cVar4;
  int iVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong lVar15;
  undefined4 uVar16;
  code *pcVar17;
  undefined8 *puVar18;
  longlong *plVar19;
  longlong **pplStack_168;
  undefined8 uStack_160;
  longlong *plStack_150;
  undefined8 uStack_148;
  longlong *plStack_140;
  longlong *plStack_130;
  undefined8 uStack_128;
  longlong *plStack_118;
  longlong *plStack_110;
  longlong lStack_108;
  longlong *plStack_100;
  longlong *plStack_f8;
  longlong *plStack_f0;
  longlong *plStack_e8;
  undefined8 *puStack_e0;
  longlong *local_b8;
  longlong *local_b0;
  longlong *local_a8;
  longlong **local_90;
  longlong *local_88;
  undefined8 local_80;
  longlong *local_78;
  undefined8 uStack_70;
  longlong *local_68;
  
  plVar7 = DAT_23ed90aa8;
  plVar14 = (longlong *)*param_3;
  plVar1 = (longlong *)param_3[1];
  if (DAT_23ed90aa8 == (longlong *)0x0) {
LAB_23aabb2e9:
    puStack_e0 = (undefined8 *)0x23aabb305;
    DAT_23ed90aa8 = (longlong *)FUN_23e91f3b0(param_1,DAT_23ed90aa0,DAT_23ed90b40,0x28);
  }
  else {
    lVar10 = *DAT_23ed90aa8;
    if (1 < lVar10) {
      *DAT_23ed90aa8 = lVar10 + -1;
      goto LAB_23aabb2e9;
    }
    if (DAT_23ed90aa8[2] != 0) {
      *DAT_23ed90aa8 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        puStack_e0 = (undefined8 *)0x23aabb672;
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23aabb2e9;
    }
  }
  plVar13 = DAT_23ed90aa8;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar7 = DAT_23ed90aa8 + 9;
  lVar6 = *(longlong *)(lVar10 + 8);
  DAT_23ed90aa8[0xf] = lVar6;
  *(longlong **)(lVar10 + 8) = plVar7;
  if ((lVar6 != 0) &&
     (((*(char *)(lVar6 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar6 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar6 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar6 + 0x38))
       ) && (plVar13[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar6 + 0x28);
    *(longlong **)(plVar13[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  *plVar13 = *plVar13 + 1;
  *(undefined4 *)(plVar13 + 8) = 0;
  puStack_e0 = (undefined8 *)0x23aabb371;
  lVar6 = FUN_23ebc07d0();
  lVar10 = DAT_23ed8f588;
  if (lVar6 == 0) {
    plVar9 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    puStack_e0 = (undefined8 *)0x23aabbe29;
    FUN_23e915740(param_1,&local_78,DAT_23ed8f388);
    uVar16 = 0xc3;
    plVar11 = (longlong *)0x0;
    plVar7 = local_68;
    plVar12 = DAT_23ed6a4f8;
    local_90 = (longlong **)uStack_70;
    local_88 = local_78;
    plVar3 = local_80;
    goto joined_r0x00023aabbaf3;
  }
  *(undefined4 *)(plVar13 + 5) = 0xc3;
  puStack_e0 = (undefined8 *)0x23aabb3a1;
  plVar7 = (longlong *)FUN_23e915840(param_1,lVar6,DAT_23ed8f390,*(undefined8 *)(lVar10 + 0x18));
  if (plVar7 == (longlong *)0x0) {
    local_88 = *(longlong **)(param_1 + 0x60);
    plVar7 = *(longlong **)(param_1 + 0x70);
    plVar9 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar8 = (longlong *)0x0;
    uVar16 = 0xc3;
    local_90 = *(longlong ***)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = (longlong *)0x0;
    plVar12 = DAT_23ed6a4f8;
    plVar3 = local_80;
    goto joined_r0x00023aabbaf3;
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    puStack_e0 = (undefined8 *)0x23aabb64a;
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  puStack_e0 = (undefined8 *)0x23aabb3bf;
  iVar5 = FUN_23a35f020(plVar1);
  if (iVar5 == -1) {
    local_88 = *(longlong **)(param_1 + 0x60);
    plVar7 = *(longlong **)(param_1 + 0x70);
    plVar9 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar16 = 0xc6;
    plVar8 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    local_90 = *(longlong ***)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar12 = DAT_23ed6a4f8;
    plVar3 = local_80;
    goto joined_r0x00023aabbaf3;
  }
  plVar11 = (longlong *)0x0;
  if (iVar5 != 0) {
    puStack_e0 = (undefined8 *)0x23aabb685;
    lVar10 = FUN_23ebc0680();
    if (lVar10 == 0) {
      plVar9 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      puStack_e0 = (undefined8 *)0x23aabc181;
      FUN_23e915740(param_1,&local_78,DAT_23ed8f590);
      uVar16 = 199;
      plVar11 = (longlong *)0x0;
      plVar7 = local_68;
      plVar12 = DAT_23ed6a4f8;
      local_90 = (longlong **)uStack_70;
      local_88 = local_78;
      plVar3 = local_80;
      goto joined_r0x00023aabbaf3;
    }
    *(undefined4 *)(plVar13 + 5) = 199;
    puStack_e0 = (undefined8 *)0x23aabb6a3;
    plVar11 = (longlong *)FUN_23e91a870(param_1,lVar10);
    if (plVar11 == (longlong *)0x0) {
      local_88 = *(longlong **)(param_1 + 0x60);
      plVar7 = *(longlong **)(param_1 + 0x70);
      plVar9 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar8 = (longlong *)0x0;
      uVar16 = 199;
      local_90 = *(longlong ***)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar12 = DAT_23ed6a4f8;
      plVar3 = local_80;
      goto joined_r0x00023aabbaf3;
    }
    puStack_e0 = (undefined8 *)0x23aabb6be;
    plVar12 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed8f598);
    if (plVar12 == (longlong *)0x0) {
      local_88 = *(longlong **)(param_1 + 0x60);
      plVar7 = *(longlong **)(param_1 + 0x70);
      plVar8 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar16 = 200;
      local_90 = *(longlong ***)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar9 = (longlong *)0x0;
      plVar12 = DAT_23ed6a4f8;
      plVar3 = local_80;
      goto joined_r0x00023aabbaf3;
    }
    puStack_e0 = (undefined8 *)0x23aabb6cf;
    lVar10 = FUN_23ebc0680();
    if (lVar10 == 0) {
      puStack_e0 = (undefined8 *)0x23aabc204;
      FUN_23e915740(param_1,&local_78,DAT_23ed8f590);
      *plVar12 = *plVar12 + -1;
      lVar10 = *plVar12;
      local_88 = local_78;
      local_90 = (longlong **)uStack_70;
      plVar7 = local_68;
    }
    else {
      puStack_e0 = (undefined8 *)0x23aabb6ea;
      plVar7 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23ed8f5a0);
      if (plVar7 != (longlong *)0x0) {
        puStack_e0 = (undefined8 *)0x23aabb705;
        plVar9 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed8f5a8);
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          puStack_e0 = (undefined8 *)0x23aabb718;
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        if (plVar9 == (longlong *)0x0) {
          local_88 = *(longlong **)(param_1 + 0x60);
          plVar7 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          local_90 = *(longlong ***)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            plVar8 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            puStack_e0 = (undefined8 *)0x23aabc270;
            (**(code **)(plVar12[1] + 0x30))(plVar12);
            uVar16 = 200;
            plVar12 = DAT_23ed6a4f8;
            plVar3 = local_80;
          }
          else {
            plVar9 = (longlong *)0x0;
            plVar8 = (longlong *)0x0;
            uVar16 = 200;
            plVar12 = DAT_23ed6a4f8;
            plVar3 = local_80;
          }
          goto joined_r0x00023aabbaf3;
        }
        *(undefined4 *)(plVar13 + 5) = 200;
        puStack_e0 = (undefined8 *)0x23aabb736;
        plVar7 = (longlong *)FUN_23e914090(param_1,plVar12,plVar9);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          puStack_e0 = (undefined8 *)0x23aabb74a;
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          puStack_e0 = (undefined8 *)0x23aabb75c;
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar7 == (longlong *)0x0) {
          local_88 = *(longlong **)(param_1 + 0x60);
          plVar7 = *(longlong **)(param_1 + 0x70);
          plVar9 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar16 = 200;
          local_90 = *(longlong ***)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar8 = (longlong *)0x0;
          plVar12 = DAT_23ed6a4f8;
          plVar3 = local_80;
          goto joined_r0x00023aabbaf3;
        }
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          puStack_e0 = (undefined8 *)0x23aabc01a;
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        lVar10 = DAT_23ed8f5b8;
        *(undefined4 *)(plVar13 + 5) = 0xc9;
        puStack_e0 = (undefined8 *)0x23aabb793;
        plVar7 = (longlong *)
                 FUN_23e915840(param_1,plVar11,DAT_23ed8f5b0,*(undefined8 *)(lVar10 + 0x18));
        if (plVar7 == (longlong *)0x0) {
          local_88 = *(longlong **)(param_1 + 0x60);
          plVar7 = *(longlong **)(param_1 + 0x70);
          plVar9 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar16 = 0xc9;
          local_90 = *(longlong ***)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar8 = (longlong *)0x0;
          plVar12 = DAT_23ed6a4f8;
          plVar3 = local_80;
          goto joined_r0x00023aabbaf3;
        }
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          puStack_e0 = (undefined8 *)0x23aabc03a;
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        lVar10 = DAT_23ed8f5c8;
        *(undefined4 *)(plVar13 + 5) = 0xca;
        puStack_e0 = (undefined8 *)0x23aabb7cd;
        puVar18 = DAT_23ed8f5c0;
        plVar7 = (longlong *)
                 FUN_23e915840(param_1,plVar11,DAT_23ed8f5c0,*(undefined8 *)(lVar10 + 0x18));
        if (plVar7 == (longlong *)0x0) {
          local_88 = *(longlong **)(param_1 + 0x60);
          plVar7 = *(longlong **)(param_1 + 0x70);
          plVar9 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar16 = 0xca;
          local_90 = *(longlong ***)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar8 = (longlong *)0x0;
          plVar12 = DAT_23ed6a4f8;
          plVar3 = local_80;
          goto joined_r0x00023aabbaf3;
        }
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          puStack_e0 = (undefined8 *)0x23aabc04a;
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        puStack_e0 = (undefined8 *)0x23aabb7f2;
        plVar12 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed8f5d0);
        uVar2 = DAT_23ed6cd28;
        if (plVar12 == (longlong *)0x0) {
          local_88 = *(longlong **)(param_1 + 0x60);
          plVar7 = *(longlong **)(param_1 + 0x70);
          plVar8 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar16 = 0xcb;
          local_90 = *(longlong ***)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar9 = (longlong *)0x0;
          plVar12 = DAT_23ed6a4f8;
          plVar3 = local_80;
          goto joined_r0x00023aabbaf3;
        }
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          puStack_e0 = (undefined8 *)0x23aabc387;
          plVar7 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar7 == (longlong *)0x0) {
            puStack_e0 = (undefined8 *)0x23aabc633;
            PyErr_PrintEx(0,0);
            lVar10 = 1;
            puStack_e0 = (undefined8 *)0x23aabc63e;
            Py_Exit();
            plVar3 = _DAT_23ed90a90;
            puStack_e0 = &DAT_23ed6a4c0;
            uStack_128 = uVar2;
            plVar7 = (longlong *)*puVar18;
            plVar8 = (longlong *)puVar18[1];
            plStack_130 = plVar1;
            plStack_118 = plVar13;
            plStack_110 = plVar11;
            lStack_108 = param_1;
            plStack_100 = plVar12;
            plStack_f8 = plVar9;
            plStack_f0 = plVar1;
            plStack_e8 = plVar14;
            if (_DAT_23ed90a90 == (longlong *)0x0) {
LAB_23aabc686:
              _DAT_23ed90a90 = (longlong *)FUN_23e91f3b0(lVar10,DAT_23ed90a88,DAT_23ed90b40,0x20);
            }
            else {
              lVar6 = *_DAT_23ed90a90;
              if (1 < lVar6) {
                *_DAT_23ed90a90 = lVar6 + -1;
                goto LAB_23aabc686;
              }
              if (_DAT_23ed90a90[2] != 0) {
                *_DAT_23ed90a90 = lVar6 + -1;
                if (lVar6 + -1 == 0) {
                  (**(code **)(plVar3[1] + 0x30))(plVar3);
                }
                goto LAB_23aabc686;
              }
            }
            plVar1 = _DAT_23ed90a90;
            lVar6 = *(longlong *)(lVar10 + 0x38);
            plVar14 = _DAT_23ed90a90 + 9;
            lVar15 = *(longlong *)(lVar6 + 8);
            _DAT_23ed90a90[0xf] = lVar15;
            *(longlong **)(lVar6 + 8) = plVar14;
            if (((lVar15 != 0) &&
                ((*(char *)(lVar15 + 0x45) == '\x01' ||
                 ((ulonglong)
                  (*(longlong *)(lVar15 + 0x20) + 0xb8 +
                  (longlong)*(int *)(*(longlong *)(lVar15 + 0x20) + 0xa8) * 2) <=
                  *(ulonglong *)(lVar15 + 0x38))))) && (plVar1[0xe] != 0)) {
              plVar14 = *(longlong **)(lVar15 + 0x28);
              *(longlong **)(plVar1[0xe] + 0x10) = plVar14;
              if (plVar14 != (longlong *)0x0) {
                *plVar14 = *plVar14 + 1;
              }
            }
            *plVar1 = *plVar1 + 1;
            *(undefined4 *)(plVar1 + 8) = 0;
            lVar6 = FUN_23ebc07d0();
            if (lVar6 == 0) {
              plVar11 = (longlong *)0x0;
              FUN_23e915740(lVar10,&plStack_150,DAT_23ed8f388);
              uVar16 = 0xe6;
              pplStack_168 = (longlong **)plStack_150;
              uStack_160 = uStack_148;
              plVar13 = (longlong *)0x0;
              plVar14 = plStack_140;
              goto LAB_23aabcc40;
            }
            plVar13 = (longlong *)FUN_23e8bc2f0(lVar6,DAT_23ed8f3c0);
            plVar14 = _DAT_23ed8f630;
            if (plVar13 == (longlong *)0x0) {
              pplStack_168 = *(longlong ***)(lVar10 + 0x60);
              plVar14 = *(longlong **)(lVar10 + 0x70);
              plVar11 = (longlong *)0x0;
              *(undefined8 *)(lVar10 + 0x70) = 0;
              uVar16 = 0xe6;
              uStack_160 = *(undefined8 *)(lVar10 + 0x68);
              *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23aabcc40;
            }
            lVar6 = *(longlong *)(lVar10 + 0x10);
            plVar9 = *(longlong **)(lVar6 + 0xe20);
            if (plVar9 == (longlong *)0x0) {
              plVar9 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
            }
            else {
              lVar15 = plVar9[3];
              *(int *)(lVar6 + 0xebc) = *(int *)(lVar6 + 0xebc) + -1;
              *(longlong *)(lVar6 + 0xe20) = lVar15;
              *plVar9 = 1;
            }
            pcVar17 = _PyRuntime_exref;
            plVar11 = (longlong *)&DAT_23ed6a4c0;
            plVar9[4] = 0;
            lVar6 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar17 + 0x1f8) + 0x10) + 0x2e8);
            lVar15 = plVar9[-1];
            puVar18 = *(undefined8 **)(lVar6 + 8);
            *puVar18 = plVar9 + -2;
            plVar9[-2] = lVar6;
            plVar9[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar18;
            *(longlong **)(lVar6 + 8) = plVar9 + -2;
            plVar12 = DAT_23ed6a4c0;
            *plVar14 = *plVar14 + 1;
            plVar9[3] = (longlong)plVar14;
            uVar2 = DAT_23ed6cd28;
            if (plVar12 == (longlong *)0x0) {
              plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar12 != (longlong *)0x0) {
                *plVar12 = *plVar12 + 1;
                DAT_23ed6a4c0 = plVar12;
                goto LAB_23aabc7e2;
              }
              PyErr_PrintEx(0,0);
              Py_Exit(1);
LAB_23aabd1b0:
              plVar9 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23ed8f648);
              if (plVar9 == (longlong *)0x0) {
LAB_23aabd2ec:
                pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                plVar14 = *(longlong **)(lVar10 + 0x70);
                uVar16 = 0xec;
                *(undefined8 *)(lVar10 + 0x70) = 0;
                uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23aabcc40;
              }
              iVar5 = FUN_23a35f020(plVar9);
              lVar6 = *plVar9 + -1;
              if (iVar5 == -1) {
                pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                plVar14 = *(longlong **)(lVar10 + 0x70);
                *(undefined8 *)(lVar10 + 0x70) = 0;
                uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                *plVar9 = lVar6;
                if (lVar6 == 0) {
                  FUN_23a334bc0();
                }
                uVar16 = 0xec;
                goto LAB_23aabcc40;
              }
              *plVar9 = lVar6;
              if (lVar6 == 0) {
                (**(code **)(plVar9[1] + 0x30))();
              }
              if (iVar5 == 1) {
                lVar15 = FUN_23ebc07d0();
                lVar6 = _DAT_23ed8f650;
                if (lVar15 == 0) {
                  FUN_23e915740(lVar10,pplStack_168,DAT_23ed8f388);
                  uVar16 = 0xed;
                  pplStack_168 = (longlong **)plStack_150;
                  uStack_160 = uStack_148;
                  plVar14 = plStack_140;
                  goto LAB_23aabcc40;
                }
                *(undefined4 *)(plVar1 + 5) = 0xed;
                plVar14 = (longlong *)
                          FUN_23e915840(lVar10,lVar15,DAT_23ed8f390,*(undefined8 *)(lVar6 + 0x18));
                if (plVar14 == (longlong *)0x0) {
                  pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                  plVar14 = *(longlong **)(lVar10 + 0x70);
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  uVar16 = 0xed;
                  uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23aabcc40;
                }
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                *(undefined4 *)(plVar1 + 5) = 0xee;
                plVar14 = (longlong *)FUN_23e91bfe0(lVar10,plVar11,_DAT_23ed8f658);
                if (plVar14 == (longlong *)0x0) {
                  pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                  plVar14 = *(longlong **)(lVar10 + 0x70);
                  uVar16 = 0xee;
                  uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  goto LAB_23aabcc40;
                }
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
              }
LAB_23aabcb90:
              iVar5 = FUN_23e8be270(lVar10,plVar13,_DAT_23ed8f660);
              if (iVar5 == -1) {
                pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                plVar14 = *(longlong **)(lVar10 + 0x70);
                uVar16 = 0xf0;
                *(undefined8 *)(lVar10 + 0x70) = 0;
                uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23aabcc40;
              }
              if ((iVar5 != 0) &&
                 (cVar4 = FUN_23e8d9ac0(plVar13,_DAT_23ed8f660,_Py_FalseStruct_exref), cVar4 == '\0'
                 )) {
                pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                plVar14 = *(longlong **)(lVar10 + 0x70);
                uVar16 = 0xf1;
                *(undefined8 *)(lVar10 + 0x70) = 0;
                uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23aabcc40;
              }
LAB_23aabc8d5:
              *(undefined4 *)(plVar1 + 5) = 0xf4;
              plVar14 = (longlong *)FUN_23e915840(lVar10,plVar7,DAT_23ed8f668,plVar8);
              if (plVar14 == (longlong *)0x0) {
                pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                plVar14 = *(longlong **)(lVar10 + 0x70);
                uVar16 = 0xf4;
                *(undefined8 *)(lVar10 + 0x70) = 0;
                uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                plVar14 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed8f538);
                if (plVar14 != (longlong *)0x0) {
                  plVar9 = (longlong *)FUN_23e8bc2f0(plVar14,DAT_23ed8f540);
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  if (plVar9 != (longlong *)0x0) {
                    *(undefined4 *)(plVar1 + 5) = 0xf7;
                    plVar14 = (longlong *)FUN_23e915840(lVar10,plVar9,_DAT_23ed8f670,plVar8);
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                    }
                    if (plVar14 != (longlong *)0x0) {
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      lVar6 = *(longlong *)(*(longlong *)(lVar10 + 0x38) + 8);
                      plVar14 = *(longlong **)(lVar6 + 0x28);
                      plVar1 = (longlong *)plVar14[2];
                      *(undefined8 *)(*(longlong *)(lVar10 + 0x38) + 8) =
                           *(undefined8 *)(lVar6 + 0x30);
                      *(undefined4 *)(plVar14 + 8) = 0xffffffff;
                      if (plVar1 != (longlong *)0x0) {
                        plVar14[2] = 0;
                        *plVar1 = *plVar1 + -1;
                        if (*plVar1 == 0) {
                          (**(code **)(plVar1[1] + 0x30))();
                        }
                      }
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      plVar14[0xf] = 0;
                      pcVar17 = _Py_NoneStruct_exref;
                      *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                      if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0))
                      {
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0))
                      {
                        (**(code **)(plVar11[1] + 0x30))(plVar11);
                      }
                      *plVar7 = *plVar7 + -1;
                      if (*plVar7 == 0) {
                        (**(code **)(plVar7[1] + 0x30))(plVar7);
                      }
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 == 0) {
                        (**(code **)(plVar8[1] + 0x30))(plVar8);
                        return pcVar17;
                      }
                      return pcVar17;
                    }
                  }
                }
                pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                plVar14 = *(longlong **)(lVar10 + 0x70);
                uVar16 = 0xf7;
                *(undefined8 *)(lVar10 + 0x70) = 0;
                uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
              }
            }
            else {
LAB_23aabc7e2:
              pplStack_168 = &plStack_150;
              uStack_148 = uVar2;
              plStack_150 = plVar8;
              lVar6 = FUN_23e94ed00(lVar10,plVar12,pplStack_168);
              if (lVar6 == 0) {
                pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                plVar14 = *(longlong **)(lVar10 + 0x70);
                *(undefined8 *)(lVar10 + 0x70) = 0;
                uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
              }
              else {
                plVar9[4] = lVar6;
                plVar14 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar9);
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                if (plVar14 != (longlong *)0x0) {
                  *(undefined4 *)(plVar1 + 5) = 0xe6;
                  plVar11 = (longlong *)FUN_23e914090(lVar10,plVar13,plVar14);
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  if (plVar11 == (longlong *)0x0) {
                    pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                    plVar14 = *(longlong **)(lVar10 + 0x70);
                    plVar11 = (longlong *)0x0;
                    *(undefined8 *)(lVar10 + 0x70) = 0;
                    uVar16 = 0xe6;
                    uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                    *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                    plVar13 = (longlong *)0x0;
                    goto LAB_23aabcc40;
                  }
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  plVar13 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed8f558);
                  if (plVar13 == (longlong *)0x0) {
LAB_23aabcfc0:
                    pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                    plVar14 = *(longlong **)(lVar10 + 0x70);
                    plVar11 = (longlong *)0x0;
                    *(undefined8 *)(lVar10 + 0x70) = 0;
                    uVar16 = 0xe9;
                    uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                    *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                    plVar13 = (longlong *)0x0;
                    goto LAB_23aabcc40;
                  }
                  iVar5 = FUN_23a35f020(plVar13);
                  lVar6 = *plVar13 + -1;
                  if (iVar5 == -1) {
                    pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                    plVar14 = *(longlong **)(lVar10 + 0x70);
                    *(undefined8 *)(lVar10 + 0x70) = 0;
                    uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                    *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                    *plVar13 = lVar6;
                    if (lVar6 == 0) {
                      plVar11 = (longlong *)0x0;
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                      uVar16 = 0xe9;
                      plVar13 = (longlong *)0x0;
                    }
                    else {
                      uVar16 = 0xe9;
                      plVar11 = (longlong *)0x0;
                      plVar13 = (longlong *)0x0;
                    }
                    goto LAB_23aabcc40;
                  }
                  *plVar13 = lVar6;
                  if (lVar6 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  if (iVar5 != 0) {
                    plVar14 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed8f558);
                    if (plVar14 == (longlong *)0x0) goto LAB_23aabcfc0;
                    iVar5 = FUN_23e8be270(lVar10,plVar14,_DAT_23ed8f638);
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                    if (iVar5 == -1) {
                      pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                      plVar14 = *(longlong **)(lVar10 + 0x70);
                      plVar11 = (longlong *)0x0;
                      *(undefined8 *)(lVar10 + 0x70) = 0;
                      uVar16 = 0xe9;
                      uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                      *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                      plVar13 = (longlong *)0x0;
                      goto LAB_23aabcc40;
                    }
                    if (iVar5 != 0) {
                      plVar14 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed8f558);
                      if (plVar14 == (longlong *)0x0) {
                        pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                        plVar14 = *(longlong **)(lVar10 + 0x70);
                        *(undefined8 *)(lVar10 + 0x70) = 0;
                        uVar16 = 0xea;
                        uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                        *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                        plVar11 = (longlong *)0x0;
                        plVar13 = (longlong *)0x0;
                        goto LAB_23aabcc40;
                      }
                      plVar13 = (longlong *)FUN_23e8bc2f0(plVar14,_DAT_23ed8f638);
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      if (plVar13 == (longlong *)0x0) {
                        pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                        plVar14 = *(longlong **)(lVar10 + 0x70);
                        plVar11 = (longlong *)0x0;
                        *(undefined8 *)(lVar10 + 0x70) = 0;
                        uVar16 = 0xea;
                        uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                        *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23aabcc40;
                      }
                      plVar11 = (longlong *)
                                FUN_23e8bbbe0(lVar10,plVar13,_DAT_23ed8f640,_Py_NoneStruct_exref);
                      if (plVar11 == (longlong *)0x0) {
                        pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                        plVar14 = *(longlong **)(lVar10 + 0x70);
                        uVar16 = 0xeb;
                        *(undefined8 *)(lVar10 + 0x70) = 0;
                        uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                        *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23aabcc40;
                      }
                      iVar5 = FUN_23a35f020(plVar11);
                      if (iVar5 != -1) {
                        if (iVar5 != 0) goto LAB_23aabd1b0;
                        goto LAB_23aabcb90;
                      }
                      goto LAB_23aabd2ec;
                    }
                  }
                  plVar11 = (longlong *)0x0;
                  plVar13 = (longlong *)0x0;
                  goto LAB_23aabc8d5;
                }
                pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                plVar14 = *(longlong **)(lVar10 + 0x70);
                *(undefined8 *)(lVar10 + 0x70) = 0;
                uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                *plVar13 = *plVar13 + -1;
                plVar11 = (longlong *)0x0;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                  uVar16 = 0xe6;
                  plVar13 = (longlong *)0x0;
                  goto LAB_23aabcc40;
                }
              }
              plVar11 = (longlong *)0x0;
              uVar16 = 0xe6;
              plVar13 = (longlong *)0x0;
            }
LAB_23aabcc40:
            plVar9 = DAT_23ed6a4f8;
            if (plVar14 == (longlong *)0x0) {
              if (DAT_23ed6a4f8 == (longlong *)0x0) {
                plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
              }
              else {
                plVar14 = (longlong *)*DAT_23ed6a4f8;
                *DAT_23ed6a4f8 = 1;
                DAT_23ed6a4f8 = plVar14;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              pcVar17 = _PyRuntime_exref;
              plVar9[2] = 0;
              plVar9[3] = (longlong)plVar1;
              *plVar1 = *plVar1 + 1;
              lVar6 = *(longlong *)(pcVar17 + 0x1f8);
              *(undefined4 *)((longlong)plVar9 + 0x24) = uVar16;
              lVar6 = *(longlong *)(lVar6 + 0x10);
              *(undefined4 *)(plVar9 + 4) = 0xffffffff;
              lVar6 = *(longlong *)(lVar6 + 0x2e8);
              lVar15 = plVar9[-1];
              puVar18 = *(undefined8 **)(lVar6 + 8);
              *puVar18 = plVar9 + -2;
              plVar9[-2] = lVar6;
              plVar9[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar18;
              *(longlong **)(lVar6 + 8) = plVar9 + -2;
              plVar12 = plVar9;
            }
            else {
              plVar12 = plVar14;
              if ((longlong *)plVar14[3] != plVar1) {
                if (DAT_23ed6a4f8 == (longlong *)0x0) {
                  plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
                }
                else {
                  plVar12 = (longlong *)*DAT_23ed6a4f8;
                  *DAT_23ed6a4f8 = 1;
                  DAT_23ed6a4f8 = plVar12;
                  DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                }
                plVar9[3] = (longlong)plVar1;
                *plVar1 = *plVar1 + 1;
                *(undefined4 *)((longlong)plVar9 + 0x24) = uVar16;
                pcVar17 = _PyRuntime_exref;
                *(undefined4 *)(plVar9 + 4) = 0xffffffff;
                lVar6 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar17 + 0x1f8) + 0x10) + 0x2e8);
                lVar15 = plVar9[-1];
                puVar18 = *(undefined8 **)(lVar6 + 8);
                *puVar18 = plVar9 + -2;
                plVar9[-2] = lVar6;
                plVar9[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar18;
                lVar15 = *plVar14;
                *(longlong **)(lVar6 + 8) = plVar9 + -2;
                plVar9[2] = (longlong)plVar14;
                plVar12 = plVar9;
                if (lVar15 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
              }
            }
            FUN_23e8bba40(plVar1,&DAT_23ec31985,plVar7,plVar8,plVar13,plVar11);
            if (_DAT_23ed90a90 == plVar1) {
              *plVar1 = *plVar1 + -1;
              if (*plVar1 == 0) {
                (**(code **)(plVar1[1] + 0x30))(plVar1);
              }
              _DAT_23ed90a90 = (longlong *)0x0;
            }
            lVar6 = *(longlong *)(*(longlong *)(lVar10 + 0x38) + 8);
            plVar14 = *(longlong **)(lVar6 + 0x28);
            plVar1 = (longlong *)plVar14[2];
            *(undefined8 *)(*(longlong *)(lVar10 + 0x38) + 8) = *(undefined8 *)(lVar6 + 0x30);
            *(undefined4 *)(plVar14 + 8) = 0xffffffff;
            if (plVar1 != (longlong *)0x0) {
              plVar14[2] = 0;
              *plVar1 = *plVar1 + -1;
              if (*plVar1 == 0) {
                (**(code **)(plVar1[1] + 0x30))();
              }
            }
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            plVar14[0xf] = 0;
            if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            FUN_23a33aa70(lVar10,pplStack_168,uStack_160,plVar12);
            return (code *)0x0;
          }
          *plVar7 = *plVar7 + 1;
          DAT_23ed6a4c0 = plVar7;
        }
        local_90 = &local_78;
        uStack_70 = uVar2;
        puStack_e0 = (undefined8 *)0x23aabb83b;
        local_78 = plVar1;
        lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,local_90);
        if (lVar10 != 0) {
          lVar6 = *(longlong *)(param_1 + 0x10);
          plVar7 = *(longlong **)(lVar6 + 0xe20);
          if (plVar7 == (longlong *)0x0) {
            puStack_e0 = (undefined8 *)0x23aabc099;
            plVar7 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar15 = plVar7[3];
            *(int *)(lVar6 + 0xebc) = *(int *)(lVar6 + 0xebc) + -1;
            *(longlong *)(lVar6 + 0xe20) = lVar15;
            *plVar7 = 1;
          }
          lVar6 = *(longlong *)
                   (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
          lVar15 = plVar7[-1];
          puVar18 = *(undefined8 **)(lVar6 + 8);
          *puVar18 = plVar7 + -2;
          plVar9 = DAT_23ed8f5d8;
          plVar7[-2] = lVar6;
          plVar7[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar18;
          *(longlong **)(lVar6 + 8) = plVar7 + -2;
          plVar7[3] = lVar10;
          *plVar9 = *plVar9 + 1;
          plVar7[4] = (longlong)plVar9;
          puStack_e0 = (undefined8 *)0x23aabb8e7;
          plVar9 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar7);
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            puStack_e0 = (undefined8 *)0x23aabb8fc;
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          if (plVar9 != (longlong *)0x0) {
            *(undefined4 *)(plVar13 + 5) = 0xcb;
            puStack_e0 = (undefined8 *)0x23aabb91a;
            plVar7 = (longlong *)FUN_23e914090(param_1,plVar12,plVar9);
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              puStack_e0 = (undefined8 *)0x23aabb92e;
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              puStack_e0 = (undefined8 *)0x23aabb93e;
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            if (plVar7 == (longlong *)0x0) {
              local_88 = *(longlong **)(param_1 + 0x60);
              plVar7 = *(longlong **)(param_1 + 0x70);
              plVar9 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar8 = (longlong *)0x0;
              uVar16 = 0xcb;
              local_90 = *(longlong ***)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar12 = DAT_23ed6a4f8;
              plVar3 = local_80;
              goto joined_r0x00023aabbaf3;
            }
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              puStack_e0 = (undefined8 *)0x23aabb959;
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
            puStack_e0 = (undefined8 *)0x23aabb968;
            plVar12 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed8f5e0);
            if (plVar12 == (longlong *)0x0) {
              local_88 = *(longlong **)(param_1 + 0x60);
              plVar7 = *(longlong **)(param_1 + 0x70);
              plVar8 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar16 = 0xd1;
              local_90 = *(longlong ***)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar9 = (longlong *)0x0;
              plVar12 = DAT_23ed6a4f8;
              plVar3 = local_80;
              goto joined_r0x00023aabbaf3;
            }
            puStack_e0 = (undefined8 *)0x23aabb979;
            lVar10 = FUN_23ebc0680();
            if (lVar10 == 0) {
              puStack_e0 = (undefined8 *)0x23aabc511;
              FUN_23e915740(param_1,local_90,DAT_23ed8f590);
              *plVar12 = *plVar12 + -1;
              lVar10 = *plVar12;
              local_88 = local_78;
              local_90 = (longlong **)uStack_70;
              plVar7 = local_68;
            }
            else {
              puStack_e0 = (undefined8 *)0x23aabb994;
              plVar7 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23ed8f5e8);
              if (plVar7 != (longlong *)0x0) {
                puStack_e0 = (undefined8 *)0x23aabb9af;
                plVar9 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed8f5f0);
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  puStack_e0 = (undefined8 *)0x23aabb9c2;
                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                }
                if (plVar9 == (longlong *)0x0) {
                  local_88 = *(longlong **)(param_1 + 0x60);
                  plVar7 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  local_90 = *(longlong ***)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    plVar8 = (longlong *)0x0;
                    plVar9 = (longlong *)0x0;
                    puStack_e0 = (undefined8 *)0x23aabc579;
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                    uVar16 = 0xd1;
                    plVar12 = DAT_23ed6a4f8;
                    plVar3 = local_80;
                  }
                  else {
                    plVar9 = (longlong *)0x0;
                    plVar8 = (longlong *)0x0;
                    uVar16 = 0xd1;
                    plVar12 = DAT_23ed6a4f8;
                    plVar3 = local_80;
                  }
                  goto joined_r0x00023aabbaf3;
                }
                *(undefined4 *)(plVar13 + 5) = 0xd1;
                puStack_e0 = (undefined8 *)0x23aabb9e0;
                plVar7 = (longlong *)FUN_23e914090(param_1,plVar12,plVar9);
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  puStack_e0 = (undefined8 *)0x23aabb9f4;
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  puStack_e0 = (undefined8 *)0x23aabba06;
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                if (plVar7 == (longlong *)0x0) {
                  local_88 = *(longlong **)(param_1 + 0x60);
                  plVar7 = *(longlong **)(param_1 + 0x70);
                  plVar9 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar16 = 0xd1;
                  local_90 = *(longlong ***)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar8 = (longlong *)0x0;
                  plVar12 = DAT_23ed6a4f8;
                  plVar3 = local_80;
                  goto joined_r0x00023aabbaf3;
                }
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  puStack_e0 = (undefined8 *)0x23aabba1f;
                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                }
                *(undefined4 *)(plVar13 + 5) = 0xd2;
                puStack_e0 = (undefined8 *)0x23aabba38;
                plVar7 = (longlong *)FUN_23e91bfe0(param_1,plVar11,DAT_23ed8f5f8);
                if (plVar7 == (longlong *)0x0) {
                  local_88 = *(longlong **)(param_1 + 0x60);
                  plVar7 = *(longlong **)(param_1 + 0x70);
                  plVar9 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar16 = 0xd2;
                  local_90 = *(longlong ***)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar8 = (longlong *)0x0;
                  plVar12 = DAT_23ed6a4f8;
                  plVar3 = local_80;
                  goto joined_r0x00023aabbaf3;
                }
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  puStack_e0 = (undefined8 *)0x23aabba58;
                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                }
                goto LAB_23aabb3d2;
              }
              local_88 = *(longlong **)(param_1 + 0x60);
              plVar7 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              local_90 = *(longlong ***)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar12 = *plVar12 + -1;
              lVar10 = *plVar12;
            }
            if (lVar10 == 0) {
              plVar8 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              puStack_e0 = (undefined8 *)0x23aabc4f3;
              (**(code **)(plVar12[1] + 0x30))(plVar12);
              uVar16 = 0xd1;
              plVar12 = DAT_23ed6a4f8;
              plVar3 = local_80;
            }
            else {
              plVar8 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              uVar16 = 0xd1;
              plVar12 = DAT_23ed6a4f8;
              plVar3 = local_80;
            }
            goto joined_r0x00023aabbaf3;
          }
        }
        plVar8 = (longlong *)0x0;
        local_88 = *(longlong **)(param_1 + 0x60);
        plVar7 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_90 = *(longlong ***)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          plVar9 = (longlong *)0x0;
          puStack_e0 = (undefined8 *)0x23aabc2bd;
          (**(code **)(plVar12[1] + 0x30))(plVar12);
          uVar16 = 0xcc;
          plVar12 = DAT_23ed6a4f8;
          plVar3 = local_80;
        }
        else {
          plVar9 = (longlong *)0x0;
          uVar16 = 0xcc;
          plVar12 = DAT_23ed6a4f8;
          plVar3 = local_80;
        }
        goto joined_r0x00023aabbaf3;
      }
      local_88 = *(longlong **)(param_1 + 0x60);
      plVar7 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_90 = *(longlong ***)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar12 = *plVar12 + -1;
      lVar10 = *plVar12;
    }
    if (lVar10 == 0) {
      plVar8 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      puStack_e0 = (undefined8 *)0x23aabc1e1;
      (**(code **)(plVar12[1] + 0x30))(plVar12);
      uVar16 = 200;
      plVar12 = DAT_23ed6a4f8;
      plVar3 = local_80;
    }
    else {
      plVar8 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      uVar16 = 200;
      plVar12 = DAT_23ed6a4f8;
      plVar3 = local_80;
    }
    goto joined_r0x00023aabbaf3;
  }
LAB_23aabb3d2:
  lVar10 = *(longlong *)(DAT_23ed8f338 + 0x20);
  if (*(char *)(lVar10 + 10) == '\0') {
    puStack_e0 = (undefined8 *)0x23aabbcec;
    plVar7 = (longlong *)FUN_23a37a020(DAT_23ed8f338,DAT_23ed8f600);
    if (plVar7 == (longlong *)0x0) goto LAB_23aabba89;
    lVar6 = *plVar7;
LAB_23aabbcf8:
    if (lVar6 == 0) goto LAB_23aabba89;
  }
  else {
    iVar5 = *(int *)(lVar10 + 0xc);
    if (*(int *)(lVar10 + 0xc) == 0) {
      *(int *)(lVar10 + 0xc) = DAT_23ec10790;
      iVar5 = DAT_23ec10790;
      DAT_23ec10790 = DAT_23ec10790 + 1;
    }
    if (DAT_23ec1076c != iVar5) {
      puStack_e0 = (undefined8 *)0x23aabba79;
      DAT_23ec1076c = iVar5;
      DAT_23ed90a98 = FUN_23e8cbd60(lVar10,DAT_23ed8f600,*(undefined8 *)(DAT_23ed8f600 + 0x18));
    }
    if (-1 < DAT_23ed90a98) {
      lVar15 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
      lVar6 = *(longlong *)(lVar15 + 8 + DAT_23ed90a98 * 0x10);
      if (lVar6 != 0) goto LAB_23aabb43f;
      puStack_e0 = (undefined8 *)0x23aabc123;
      DAT_23ed90a98 = FUN_23e8cbd60(lVar10,DAT_23ed8f600,*(undefined8 *)(DAT_23ed8f600 + 0x18));
      if (-1 < DAT_23ed90a98) {
        lVar6 = *(longlong *)(lVar15 + 8 + DAT_23ed90a98 * 0x10);
        goto LAB_23aabbcf8;
      }
    }
LAB_23aabba89:
    puStack_e0 = (undefined8 *)0x23aabba9f;
    plVar7 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23ed8f600);
    if ((plVar7 == (longlong *)0x0) || (lVar6 = *plVar7, lVar6 == 0)) {
      plVar9 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      puStack_e0 = (undefined8 *)0x23aabbac9;
      FUN_23e915740(param_1,&local_78,DAT_23ed8f600);
      uVar16 = 0xd5;
      plVar7 = local_68;
      plVar12 = DAT_23ed6a4f8;
      local_90 = (longlong **)uStack_70;
      local_88 = local_78;
      plVar3 = local_80;
      goto joined_r0x00023aabbaf3;
    }
  }
LAB_23aabb43f:
  puStack_e0 = (undefined8 *)0x23aabb44e;
  plVar7 = (longlong *)FUN_23e8bc2f0(plVar14,DAT_23ed8f528);
  if (plVar7 == (longlong *)0x0) {
    local_88 = *(longlong **)(param_1 + 0x60);
    plVar7 = *(longlong **)(param_1 + 0x70);
    plVar8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar16 = 0xd5;
    local_90 = *(longlong ***)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar9 = (longlong *)0x0;
    plVar12 = DAT_23ed6a4f8;
    plVar3 = local_80;
  }
  else {
    *(undefined4 *)(plVar13 + 5) = 0xd5;
    puStack_e0 = (undefined8 *)0x23aabb46f;
    plVar8 = (longlong *)FUN_23e914090(param_1,lVar6,plVar7);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      puStack_e0 = (undefined8 *)0x23aabbcba;
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    if (plVar8 == (longlong *)0x0) {
      local_88 = *(longlong **)(param_1 + 0x60);
      plVar7 = *(longlong **)(param_1 + 0x70);
      plVar9 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar16 = 0xd5;
      local_90 = *(longlong ***)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar12 = DAT_23ed6a4f8;
      plVar3 = local_80;
    }
    else {
      *(undefined4 *)(plVar13 + 5) = 0xd6;
      puStack_e0 = (undefined8 *)0x23aabb49f;
      plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,DAT_23ed8f5f8);
      if (plVar9 == (longlong *)0x0) {
        local_88 = *(longlong **)(param_1 + 0x60);
        plVar7 = *(longlong **)(param_1 + 0x70);
        uVar16 = 0xd6;
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_90 = *(longlong ***)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar12 = DAT_23ed6a4f8;
        plVar3 = local_80;
      }
      else {
        puStack_e0 = (undefined8 *)0x23aabb4ba;
        plVar7 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed8f608);
        if (plVar7 != (longlong *)0x0) {
          puStack_e0 = (undefined8 *)0x23aabb4d5;
          local_90 = (longlong **)FUN_23e8bc2f0(plVar7,DAT_23ed8f610);
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            puStack_e0 = (undefined8 *)0x23aabbcd0;
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          if (local_90 != (longlong **)0x0) {
            puStack_e0 = (undefined8 *)0x23aabb4fc;
            iVar5 = FUN_23e912620(plVar9,local_90);
            *local_90 = (longlong *)((longlong)*local_90 + -1);
            if (*local_90 == (longlong *)0x0) {
              puStack_e0 = (undefined8 *)0x23aabb514;
              (**(code **)((longlong)local_90[1] + 0x30))(local_90);
            }
            if (iVar5 != -1) {
              if (iVar5 == 1) {
                puStack_e0 = (undefined8 *)0x23aabbf25;
                lVar6 = FUN_23ebc07d0();
                lVar10 = DAT_23ed8f618;
                if (lVar6 == 0) {
                  puStack_e0 = (undefined8 *)0x23aabc497;
                  FUN_23e915740(param_1,&local_78,DAT_23ed8f388);
                  uVar16 = 0xd9;
                  plVar7 = local_68;
                  plVar12 = DAT_23ed6a4f8;
                  local_90 = (longlong **)uStack_70;
                  local_88 = local_78;
                  plVar3 = local_80;
                }
                else {
                  *(undefined4 *)(plVar13 + 5) = 0xd9;
                  puStack_e0 = (undefined8 *)0x23aabbf52;
                  plVar7 = (longlong *)
                           FUN_23e915840(param_1,lVar6,DAT_23ed8f390,*(undefined8 *)(lVar10 + 0x18))
                  ;
                  if (plVar7 != (longlong *)0x0) {
                    *plVar7 = *plVar7 + -1;
                    if (*plVar7 == 0) {
                      puStack_e0 = (undefined8 *)0x23aabbf6b;
                      (**(code **)(plVar7[1] + 0x30))(plVar7);
                    }
                    pcVar17 = _Py_TrueStruct_exref;
                    *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
                    goto LAB_23aabb57b;
                  }
                  local_88 = *(longlong **)(param_1 + 0x60);
                  plVar7 = *(longlong **)(param_1 + 0x70);
                  uVar16 = 0xd9;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  local_90 = *(longlong ***)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar12 = DAT_23ed6a4f8;
                  plVar3 = local_80;
                }
              }
              else {
                puStack_e0 = (undefined8 *)0x23aabb52d;
                lVar6 = FUN_23ebc07d0();
                lVar10 = DAT_23ed8f620;
                if (lVar6 == 0) {
                  puStack_e0 = (undefined8 *)0x23aabc34c;
                  FUN_23e915740(param_1,&local_78,DAT_23ed8f388);
                  uVar16 = 0xdc;
                  plVar7 = local_68;
                  plVar12 = DAT_23ed6a4f8;
                  local_90 = (longlong **)uStack_70;
                  local_88 = local_78;
                  plVar3 = local_80;
                }
                else {
                  *(undefined4 *)(plVar13 + 5) = 0xdc;
                  puStack_e0 = (undefined8 *)0x23aabb55a;
                  plVar7 = (longlong *)
                           FUN_23e915840(param_1,lVar6,DAT_23ed8f390,*(undefined8 *)(lVar10 + 0x18))
                  ;
                  if (plVar7 != (longlong *)0x0) {
                    *plVar7 = *plVar7 + -1;
                    if (*plVar7 == 0) {
                      puStack_e0 = (undefined8 *)0x23aabc027;
                      (**(code **)(plVar7[1] + 0x30))(plVar7);
                    }
                    pcVar17 = _Py_FalseStruct_exref;
                    *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
LAB_23aabb57b:
                    lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                    plVar7 = *(longlong **)(lVar10 + 0x28);
                    plVar13 = (longlong *)plVar7[2];
                    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                         *(undefined8 *)(lVar10 + 0x30);
                    *(undefined4 *)(plVar7 + 8) = 0xffffffff;
                    if (plVar13 != (longlong *)0x0) {
                      plVar7[2] = 0;
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        puStack_e0 = (undefined8 *)0x23aabc007;
                        (**(code **)(plVar13[1] + 0x30))();
                      }
                    }
                    *plVar7 = *plVar7 + -1;
                    if (*plVar7 == 0) {
                      puStack_e0 = (undefined8 *)0x23aabb5c1;
                      (**(code **)(plVar7[1] + 0x30))(plVar7);
                    }
                    plVar7[0xf] = 0;
                    if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                      puStack_e0 = (undefined8 *)0x23aabbffa;
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      puStack_e0 = (undefined8 *)0x23aabb5e8;
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                    }
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      puStack_e0 = (undefined8 *)0x23aabb5f9;
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                    }
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      puStack_e0 = (undefined8 *)0x23aabb609;
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                    *plVar1 = *plVar1 + -1;
                    if (*plVar1 == 0) {
                      puStack_e0 = (undefined8 *)0x23aabb61a;
                      (**(code **)(plVar1[1] + 0x30))(plVar1);
                      return pcVar17;
                    }
                    return pcVar17;
                  }
                  local_88 = *(longlong **)(param_1 + 0x60);
                  plVar7 = *(longlong **)(param_1 + 0x70);
                  uVar16 = 0xdc;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  local_90 = *(longlong ***)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar12 = DAT_23ed6a4f8;
                  plVar3 = local_80;
                }
              }
              goto joined_r0x00023aabbaf3;
            }
          }
        }
        local_88 = *(longlong **)(param_1 + 0x60);
        plVar7 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar16 = 0xd8;
        local_90 = *(longlong ***)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar12 = DAT_23ed6a4f8;
        plVar3 = local_80;
      }
    }
  }
joined_r0x00023aabbaf3:
  local_80._4_4_ = (undefined4)((ulonglong)plVar3 >> 0x20);
  DAT_23ed6a4f8 = plVar12;
  local_80 = plVar3;
  if (plVar7 == (longlong *)0x0) {
    if (plVar12 == (longlong *)0x0) {
      local_80 = (longlong *)CONCAT44(local_80._4_4_,uVar16);
      puStack_e0 = (undefined8 *)0x23aabc158;
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      uVar16 = SUB84(local_80,0);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar12;
      *plVar12 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar17 = _PyRuntime_exref;
    plVar12[3] = (longlong)plVar13;
    plVar12[2] = 0;
    *plVar13 = *plVar13 + 1;
    lVar10 = *(longlong *)(pcVar17 + 0x1f8);
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar16;
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
    lVar6 = plVar12[-1];
    puVar18 = *(undefined8 **)(lVar10 + 8);
    *puVar18 = plVar12 + -2;
    plVar12[-2] = lVar10;
    plVar12[-1] = (ulonglong)((uint)lVar6 & 3) | (ulonglong)puVar18;
    *(longlong **)(lVar10 + 8) = plVar12 + -2;
    plVar19 = plVar12;
    plVar3 = local_80;
  }
  else {
    plVar19 = plVar7;
    if ((longlong *)plVar7[3] != plVar13) {
      if (plVar12 == (longlong *)0x0) {
        local_80 = (longlong *)CONCAT44(local_80._4_4_,uVar16);
        puStack_e0 = (undefined8 *)0x23aabbf10;
        plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
        uVar16 = SUB84(local_80,0);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar12;
        *plVar12 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar12[3] = (longlong)plVar13;
      *plVar13 = *plVar13 + 1;
      *(undefined4 *)((longlong)plVar12 + 0x24) = uVar16;
      pcVar17 = _PyRuntime_exref;
      *(undefined4 *)(plVar12 + 4) = 0xffffffff;
      lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar17 + 0x1f8) + 0x10) + 0x2e8);
      lVar6 = plVar12[-1];
      puVar18 = *(undefined8 **)(lVar10 + 8);
      *puVar18 = plVar12 + -2;
      plVar12[-2] = lVar10;
      plVar12[-1] = (ulonglong)((uint)lVar6 & 3) | (ulonglong)puVar18;
      lVar6 = *plVar7;
      *(longlong **)(lVar10 + 8) = plVar12 + -2;
      plVar12[2] = (longlong)plVar7;
      plVar19 = plVar12;
      plVar3 = local_80;
      if (lVar6 == 0) {
        puStack_e0 = (undefined8 *)0x23aabbb9f;
        local_80 = plVar12;
        (**(code **)(plVar7[1] + 0x30))(plVar7);
        plVar19 = local_80;
        plVar3 = local_80;
      }
    }
  }
  local_80 = plVar3;
  puStack_e0 = (undefined8 *)0x23aabbbcb;
  local_b8 = plVar11;
  local_b0 = plVar8;
  local_a8 = plVar9;
  FUN_23e8bba40(plVar13,"ooooo",plVar14,plVar1);
  if (DAT_23ed90aa8 == plVar13) {
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      puStack_e0 = (undefined8 *)0x23aabbe00;
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    DAT_23ed90aa8 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar10 + 0x28);
  plVar13 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar7 + 8) = 0xffffffff;
  if (plVar13 != (longlong *)0x0) {
    plVar7[2] = 0;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      puStack_e0 = (undefined8 *)0x23aabbc11;
      (**(code **)(plVar13[1] + 0x30))();
    }
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    puStack_e0 = (undefined8 *)0x23aabbc21;
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  plVar7[0xf] = 0;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    puStack_e0 = (undefined8 *)0x23aabbc3e;
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    puStack_e0 = (undefined8 *)0x23aabbc53;
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    puStack_e0 = (undefined8 *)0x23aabbc69;
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *plVar14 = *plVar14 + -1;
  if (*plVar14 == 0) {
    puStack_e0 = (undefined8 *)0x23aabbc79;
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    puStack_e0 = (undefined8 *)0x23aabbc8a;
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  puStack_e0 = (undefined8 *)0x23aabbca1;
  FUN_23a33aa70(param_1,local_88,local_90,plVar19);
  return (code *)0x0;
}
