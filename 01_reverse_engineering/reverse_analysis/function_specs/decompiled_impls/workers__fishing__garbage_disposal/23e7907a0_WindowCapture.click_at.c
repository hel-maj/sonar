/* ===== 23e7907a0 workers.fishing.garbage_disposal:110 ===== */
/* ghidra_name=FUN_23e7907a0 entry=23e7907a0 size=10212 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

code * FUN_23e7907a0(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  int iVar8;
  uint uVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  code *pcVar17;
  longlong lVar18;
  undefined8 uVar19;
  longlong *plVar20;
  code *pcVar21;
  code *pcVar22;
  longlong *plVar23;
  code *pcVar24;
  code *pcVar25;
  undefined4 uVar26;
  longlong *local_108;
  longlong *local_100;
  longlong *local_f8;
  code *local_f0;
  longlong *local_d0;
  code *local_c0;
  longlong *local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [16];
  code *local_88 [2];
  longlong *local_78;
  code *pcStack_70;
  code *local_68;
  
  plVar10 = _DAT_23eedac90;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  plVar3 = (longlong *)param_3[2];
  plVar4 = (longlong *)param_3[3];
  if (_DAT_23eedac90 == (longlong *)0x0) {
LAB_23e790813:
    _DAT_23eedac90 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedac88,DAT_23eedacf8,0x68);
  }
  else {
    lVar11 = *_DAT_23eedac90;
    if (1 < lVar11) {
      *_DAT_23eedac90 = lVar11 + -1;
      goto LAB_23e790813;
    }
    if (_DAT_23eedac90[2] != 0) {
      *_DAT_23eedac90 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e790813;
    }
  }
  plVar5 = _DAT_23eedac90;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eedac90 + 9;
  lVar18 = *(longlong *)(lVar11 + 8);
  _DAT_23eedac90[0xf] = lVar18;
  *(longlong **)(lVar11 + 8) = plVar10;
  if ((lVar18 != 0) &&
     (((*(char *)(lVar18 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar18 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar18 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar18 + 0x38))) && (plVar5[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar18 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  uVar19 = DAT_23eed80a8;
  *(undefined4 *)(plVar5 + 8) = 0;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,uVar19);
  if (plVar10 == (longlong *)0x0) {
    local_d0 = *(longlong **)(param_1 + 0x60);
    pcVar24 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar21 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcVar24 == (code *)0x0) goto LAB_23e792039;
    plVar10 = *(longlong **)(pcVar24 + 0x18);
joined_r0x00023e7915f1:
    if (plVar5 == plVar10) {
      pcVar17 = (code *)0x0;
      local_f8 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      local_f0 = (code *)0x0;
      local_100 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      pcVar22 = pcVar24;
      pcVar25 = pcVar21;
      goto LAB_23e7916f0;
    }
LAB_23e79162e:
    plVar10 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    pcVar17 = (code *)0x0;
    local_f0 = (code *)0x0;
    local_f8 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    iVar8 = 0x70;
    local_c0 = _PyRuntime_exref;
  }
  else {
    iVar8 = FUN_23a35f020(plVar10);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (iVar8 == -1) {
LAB_23e7919c0:
      local_d0 = *(longlong **)(param_1 + 0x60);
      pcVar24 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar21 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcVar24 == (code *)0x0) goto LAB_23e792039;
      plVar10 = *(longlong **)(pcVar24 + 0x18);
      goto joined_r0x00023e7915f1;
    }
    if (iVar8 == 0) {
LAB_23e7908dd:
      pcVar21 = _Py_FalseStruct_exref;
      pcVar17 = (code *)0x0;
      plVar13 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      local_f8 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
      local_f0 = (code *)0x0;
      local_100 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
LAB_23e790921:
      lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar5 = *(longlong **)(lVar11 + 0x28);
      plVar14 = (longlong *)plVar5[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
      *(undefined4 *)(plVar5 + 8) = 0xffffffff;
      if (plVar14 != (longlong *)0x0) {
        plVar5[2] = 0;
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))();
        }
      }
      *plVar5 = *plVar5 + -1;
      if (*plVar5 == 0) {
        (**(code **)(plVar5[1] + 0x30))(plVar5);
      }
      plVar5[0xf] = 0;
      if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (plVar10 != (longlong *)0x0) {
LAB_23e790985:
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
LAB_23e791590:
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
      }
      if (plVar13 == (longlong *)0x0) goto LAB_23e79099f;
LAB_23e790994:
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
LAB_23e79099f:
      if ((local_108 != (longlong *)0x0) &&
         (lVar11 = *local_108, *local_108 = lVar11 + -1, lVar11 + -1 == 0)) {
        (**(code **)(local_108[1] + 0x30))(local_108);
      }
      if ((local_100 != (longlong *)0x0) &&
         (lVar11 = *local_100, *local_100 = lVar11 + -1, lVar11 + -1 == 0)) {
        (**(code **)(local_100[1] + 0x30))(local_100);
      }
      if ((local_f0 != (code *)0x0) &&
         (lVar11 = *(longlong *)local_f0, *(longlong *)local_f0 = lVar11 + -1, lVar11 + -1 == 0)) {
        (**(code **)(*(longlong *)(local_f0 + 8) + 0x30))(local_f0);
      }
      if ((local_f8 != (longlong *)0x0) &&
         (lVar11 = *local_f8, *local_f8 = lVar11 + -1, lVar11 + -1 == 0)) {
        (**(code **)(local_f8[1] + 0x30))(local_f8);
      }
      if ((pcVar17 != (code *)0x0) &&
         (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
        (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
      }
      lVar11 = *plVar1;
      *plVar1 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar1[1] + 0x30))(plVar1);
      }
      lVar11 = *plVar2;
      *plVar2 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar2[1] + 0x30))(plVar2);
      }
      lVar11 = *plVar3;
      *plVar3 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar3[1] + 0x30))(plVar3);
      }
      lVar11 = *plVar4;
      *plVar4 = lVar11 + -1;
      if (lVar11 + -1 != 0) {
        return pcVar21;
      }
      (**(code **)(plVar4[1] + 0x30))(plVar4);
      return pcVar21;
    }
    lVar11 = FUN_23e8dfc00();
    if (lVar11 == 0) {
      FUN_23e915740(param_1,&local_78,DAT_23eed80c0);
      local_d0 = local_78;
      pcVar21 = pcStack_70;
joined_r0x00023e79256a:
      if (local_68 == (code *)0x0) {
LAB_23e792039:
        plVar10 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
        pcVar17 = (code *)0x0;
        local_f0 = (code *)0x0;
        local_f8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        iVar8 = 0x70;
        local_c0 = _PyRuntime_exref;
LAB_23e79205d:
        pcVar22 = DAT_23ed6a4f8;
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar22 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar24 = *(code **)DAT_23ed6a4f8;
          *(undefined8 *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar24;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong *)(pcVar22 + 0x10) = 0;
        *(longlong **)(pcVar22 + 0x18) = plVar5;
        *plVar5 = *plVar5 + 1;
        lVar11 = *(longlong *)(local_c0 + 0x1f8);
        *(int *)(pcVar22 + 0x24) = iVar8;
        lVar11 = *(longlong *)(lVar11 + 0x10);
        *(undefined4 *)(pcVar22 + 0x20) = 0xffffffff;
        lVar11 = *(longlong *)(lVar11 + 0x2e8);
        lVar18 = *(longlong *)(pcVar22 + -8);
        plVar14 = *(longlong **)(lVar11 + 8);
        *plVar14 = (longlong)(pcVar22 + -0x10);
        *(longlong *)(pcVar22 + -0x10) = lVar11;
        *(ulonglong *)(pcVar22 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)plVar14;
        *(code **)(lVar11 + 8) = pcVar22 + -0x10;
        pcVar25 = pcVar21;
        goto LAB_23e7916f0;
      }
      plVar10 = *(longlong **)(local_68 + 0x18);
      pcVar24 = local_68;
      goto joined_r0x00023e7915f1;
    }
    plVar10 = (longlong *)FUN_23e8bc2f0(lVar11,_DAT_23eed8118);
    if (plVar10 == (longlong *)0x0) {
      local_d0 = *(longlong **)(param_1 + 0x60);
      local_68 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar21 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto joined_r0x00023e79256a;
    }
    plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed80a8);
    if (plVar12 == (longlong *)0x0) {
      local_d0 = *(longlong **)(param_1 + 0x60);
      pcVar21 = *(code **)(param_1 + 0x68);
      pcVar24 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar10 = *plVar10 + -1;
      plVar12 = (longlong *)0x0;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
        if (pcVar24 != (code *)0x0) {
          plVar10 = *(longlong **)(pcVar24 + 0x18);
joined_r0x00023e7926b5:
          if (plVar5 == plVar10) {
            local_f8 = (longlong *)0x0;
            pcVar17 = (code *)0x0;
            plVar10 = (longlong *)0x0;
            local_f0 = (code *)0x0;
            plVar13 = (longlong *)0x0;
            local_100 = (longlong *)0x0;
            local_108 = (longlong *)0x0;
            pcVar22 = pcVar24;
            pcVar25 = pcVar21;
            goto LAB_23e7916f0;
          }
          goto LAB_23e79162e;
        }
      }
      else if (pcVar24 != (code *)0x0) {
        plVar10 = *(longlong **)(pcVar24 + 0x18);
        goto joined_r0x00023e7926b5;
      }
      goto LAB_23e792039;
    }
    *(undefined4 *)(plVar5 + 5) = 0x70;
    plVar13 = (longlong *)FUN_23e914090(param_1,plVar10,plVar12);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (plVar13 == (longlong *)0x0) {
      local_d0 = *(longlong **)(param_1 + 0x60);
      pcVar24 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar21 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar10 = (longlong *)0x0;
      if (pcVar24 == (code *)0x0) goto LAB_23e792039;
      if (plVar5 == *(longlong **)(pcVar24 + 0x18)) {
        local_f8 = (longlong *)0x0;
        pcVar17 = (code *)0x0;
        plVar12 = (longlong *)0x0;
        local_f0 = (code *)0x0;
        plVar13 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        pcVar22 = pcVar24;
        pcVar25 = pcVar21;
        goto LAB_23e7916f0;
      }
      goto LAB_23e79162e;
    }
    uVar9 = FUN_23a35f020(plVar13);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if (uVar9 == 0xffffffff) goto LAB_23e7919c0;
    if ((uVar9 & 1) == 0) goto LAB_23e7908dd;
    lVar11 = FUN_23e8dfc00();
    if (lVar11 != 0) {
      plVar10 = (longlong *)FUN_23e8bc2f0(lVar11,_DAT_23eed8228);
      if (plVar10 == (longlong *)0x0) {
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar17 = (code *)0x0;
        plVar12 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        plVar13 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar26 = 0x75;
        local_f0 = (code *)0x0;
        local_100 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        goto LAB_23e791ad5;
      }
      plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed80a8);
      if (plVar13 == (longlong *)0x0) {
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        local_f8 = (longlong *)0x0;
        pcVar17 = (code *)0x0;
        plVar10 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
        local_f0 = (code *)0x0;
        uVar26 = 0x75;
        local_100 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        goto LAB_23e791ad5;
      }
      *(undefined4 *)(plVar5 + 5) = 0x75;
      plVar12 = (longlong *)FUN_23e914090(param_1,plVar10,plVar13);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      if (plVar12 == (longlong *)0x0) {
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar14 = *(longlong **)(param_1 + 0x60);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar24 = *(code **)(param_1 + 0x68);
        goto LAB_23e792499;
      }
      lVar11 = FUN_23e8dfc00();
      if (lVar11 == 0) {
        FUN_23e915740(param_1,&local_78,DAT_23eed80c0);
        plVar10 = (longlong *)0x0;
        pcVar21 = local_68;
        plVar14 = local_78;
        pcVar24 = pcStack_70;
LAB_23e79283f:
        local_f8 = (longlong *)0x0;
        pcVar17 = (code *)0x0;
        plVar13 = (longlong *)0x0;
        uVar26 = 0x76;
        local_f0 = (code *)0x0;
        local_100 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        goto LAB_23e791ad5;
      }
      plVar13 = (longlong *)FUN_23e8bc2f0(lVar11,_DAT_23eed8128);
      if (plVar13 == (longlong *)0x0) {
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        pcVar17 = (code *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar13 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        uVar26 = 0x76;
        local_f8 = (longlong *)0x0;
        local_f0 = (code *)0x0;
        local_100 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        local_108 = (longlong *)0x0;
        goto LAB_23e791ad5;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed80a8);
      if (plVar14 == (longlong *)0x0) {
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        lVar11 = *plVar13;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar13 = lVar11 + -1;
        if (lVar11 + -1 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        local_f8 = (longlong *)0x0;
        pcVar17 = (code *)0x0;
        plVar10 = (longlong *)0x0;
        uVar26 = 0x76;
        local_f0 = (code *)0x0;
        local_100 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        goto LAB_23e791ad5;
      }
      *(undefined4 *)(plVar5 + 5) = 0x76;
      plVar10 = (longlong *)FUN_23e914090(param_1,plVar13,plVar14);
      lVar11 = *plVar13;
      *plVar13 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (plVar10 == (longlong *)0x0) {
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar14 = *(longlong **)(param_1 + 0x60);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar24 = *(code **)(param_1 + 0x68);
        goto LAB_23e79283f;
      }
      local_108 = (longlong *)FUN_23a388650(param_1,plVar12,DAT_23eed8230,2);
      if (local_108 == (longlong *)0x0) {
LAB_23e79287e:
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        pcVar17 = (code *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar13 = (longlong *)0x0;
        uVar26 = 0x79;
        local_f8 = (longlong *)0x0;
        local_f0 = (code *)0x0;
        local_100 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e791ad5;
      }
      plVar13 = (longlong *)FUN_23a388650(param_1,plVar12,DAT_23ed6ccf0,0);
      if (plVar13 == (longlong *)0x0) {
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        lVar11 = *local_108;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *local_108 = lVar11 + -1;
        plVar13 = (longlong *)0x0;
        if (lVar11 + -1 != 0) goto LAB_23e7929ae;
        (**(code **)(local_108[1] + 0x30))(local_108);
        goto LAB_23e7929ae;
      }
      local_100 = (longlong *)FUN_23e8c6640(local_108,plVar13);
      lVar11 = *local_108;
      *local_108 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(local_108[1] + 0x30))(local_108);
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      if (local_100 == (longlong *)0x0) {
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        pcVar17 = (code *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar13 = (longlong *)0x0;
        uVar26 = 0x79;
        local_f8 = (longlong *)0x0;
        local_f0 = (code *)0x0;
        local_108 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e791ad5;
      }
      plVar14 = (longlong *)FUN_23a388650(param_1,plVar10,DAT_23eed8230,2);
      plVar13 = (longlong *)0x0;
      if (plVar14 == (longlong *)0x0) goto LAB_23e792a54;
      local_108 = (longlong *)FUN_23e8c6640(local_100,plVar14);
      lVar11 = *local_100;
      *local_100 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(local_100[1] + 0x30))(local_100);
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (local_108 == (longlong *)0x0) goto LAB_23e79287e;
      if ((code *)local_108[1] == PyLong_Type_exref) {
        plVar13 = (longlong *)
                  (**(code **)(*(longlong *)(PyLong_Type_exref + 0x60) + 0xe8))
                            (local_108,DAT_23eed8230);
        lVar11 = *local_108 + -1;
        *local_108 = lVar11;
        if (plVar13 == (longlong *)0x0) {
          if (lVar11 == 0) {
            (**(code **)(local_108[1] + 0x30))();
          }
          goto LAB_23e792aea;
        }
        if (lVar11 == 0) {
          (**(code **)(local_108[1] + 0x30))();
        }
      }
      else {
        plVar13 = (longlong *)FUN_23e8c1be0(local_108);
        lVar11 = *local_108;
        *local_108 = lVar11 + -1;
        if (lVar11 + -1 == 0) {
          (**(code **)(local_108[1] + 0x30))(local_108);
        }
        if (plVar13 == (longlong *)0x0) {
LAB_23e792aea:
          plVar14 = *(longlong **)(param_1 + 0x60);
          pcVar24 = *(code **)(param_1 + 0x68);
          pcVar21 = *(code **)(param_1 + 0x70);
          local_f8 = (longlong *)0x0;
          uVar26 = 0x79;
          pcVar17 = (code *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar13 = (longlong *)0x0;
          local_f0 = (code *)0x0;
          local_100 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e791ad5;
        }
      }
      local_100 = (longlong *)FUN_23a388650(param_1,plVar12,_DAT_23eed8238,3);
      if (local_100 == (longlong *)0x0) {
LAB_23e792b34:
        pcVar21 = *(code **)(param_1 + 0x70);
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar17 = (code *)0x0;
        uVar26 = 0x7a;
        local_f8 = (longlong *)0x0;
        local_f0 = (code *)0x0;
        local_108 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e791ad5;
      }
      plVar14 = (longlong *)FUN_23a388650(param_1,plVar12);
      if (plVar14 == (longlong *)0x0) {
        pcVar21 = *(code **)(param_1 + 0x70);
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e792b91:
        local_108 = (longlong *)0x0;
        lVar11 = *local_100;
        *local_100 = lVar11 + -1;
        if (lVar11 + -1 == 0) {
          FUN_23a334bc0(local_100);
        }
LAB_23e792bad:
        pcVar17 = (code *)0x0;
        uVar26 = 0x7a;
        local_f8 = (longlong *)0x0;
        local_f0 = (code *)0x0;
        local_100 = (longlong *)0x0;
        goto LAB_23e791ad5;
      }
      plVar15 = (longlong *)FUN_23e8c6640(local_100,plVar14);
      lVar11 = *local_100;
      *local_100 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        FUN_23a334bc0();
      }
      lVar11 = *plVar14;
      *plVar14 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        FUN_23a334bc0();
      }
      if (plVar15 == (longlong *)0x0) {
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar17 = (code *)0x0;
        uVar26 = 0x7a;
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_f8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        local_f0 = (code *)0x0;
        goto LAB_23e791ad5;
      }
      plVar14 = (longlong *)FUN_23a388650(param_1,plVar10,_DAT_23eed8238,3);
      if (plVar14 == (longlong *)0x0) {
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_100 = plVar15;
        goto LAB_23e792b91;
      }
      local_100 = (longlong *)FUN_23e8c6640(plVar15,plVar14);
      lVar11 = *plVar15;
      *plVar15 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        FUN_23a334bc0(plVar15);
      }
      lVar11 = *plVar14;
      *plVar14 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        FUN_23a334bc0(plVar14);
      }
      if (local_100 == (longlong *)0x0) goto LAB_23e792b34;
      local_108 = (longlong *)FUN_23e8c6640(local_100,plVar13);
      lVar11 = *local_100;
      *local_100 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        FUN_23a334bc0(local_100);
      }
      if (local_108 == (longlong *)0x0) {
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        goto LAB_23e792bad;
      }
      local_100 = (longlong *)FUN_23a388650(param_1,plVar12,DAT_23ed6ccf0,0);
      if (local_100 == (longlong *)0x0) {
LAB_23e792c51:
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar26 = 0x7d;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar17 = (code *)0x0;
        local_f8 = (longlong *)0x0;
        local_f0 = (code *)0x0;
        goto LAB_23e791ad5;
      }
      plVar14 = (longlong *)FUN_23e8c09e0(local_100,plVar13);
      lVar11 = *local_100;
      *local_100 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        FUN_23a334bc0(local_100);
      }
      if (plVar14 == (longlong *)0x0) {
        pcVar21 = *(code **)(param_1 + 0x70);
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar17 = (code *)0x0;
        uVar26 = 0x7d;
        local_f8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        local_f0 = (code *)0x0;
        goto LAB_23e791ad5;
      }
      local_100 = (longlong *)FUN_23e8c09e0(plVar14,plVar2);
      lVar11 = *plVar14;
      *plVar14 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        FUN_23a334bc0(plVar14);
      }
      if (local_100 == (longlong *)0x0) goto LAB_23e792c51;
      local_f0 = (code *)FUN_23a388650(param_1,plVar12);
      if (local_f0 == (code *)0x0) {
LAB_23e792d39:
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar17 = (code *)0x0;
        uVar26 = 0x7e;
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_f8 = (longlong *)0x0;
        goto LAB_23e791ad5;
      }
      plVar14 = (longlong *)FUN_23e8c09e0(local_f0,local_108);
      lVar11 = *(longlong *)local_f0;
      *(longlong *)local_f0 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        FUN_23a334bc0(local_f0);
      }
      if (plVar14 == (longlong *)0x0) {
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar17 = (code *)0x0;
        uVar26 = 0x7e;
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_f0 = (code *)0x0;
        local_f8 = (longlong *)0x0;
        goto LAB_23e791ad5;
      }
      local_f0 = (code *)FUN_23e8c09e0(plVar14,plVar3);
      lVar11 = *plVar14;
      *plVar14 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        FUN_23a334bc0(plVar14);
      }
      if (local_f0 == (code *)0x0) goto LAB_23e792d39;
      local_f8 = (longlong *)FUN_23a388650(param_1,plVar12,DAT_23ed6ccf0,0);
      if (local_f8 == (longlong *)0x0) {
LAB_23e793014:
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar17 = (code *)0x0;
        uVar26 = 0x81;
        *(undefined8 *)(param_1 + 0x70) = 0;
        goto LAB_23e791ad5;
      }
      plVar15 = (longlong *)FUN_23e8c09e0(local_f8,plVar13);
      lVar11 = *local_f8;
      *local_f8 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        FUN_23a334bc0();
      }
      if (plVar15 == (longlong *)0x0) {
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        local_f8 = (longlong *)0x0;
        uVar26 = 0x81;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar17 = (code *)0x0;
        goto LAB_23e791ad5;
      }
      plVar14 = (longlong *)FUN_23a388650(param_1,plVar10,DAT_23eed8230,2);
      if (plVar14 == (longlong *)0x0) {
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar15 = *plVar15 + -1;
        local_f8 = (longlong *)0x0;
        if (*plVar15 == 0) {
          pcVar17 = (code *)0x0;
          FUN_23a334bc0(plVar15);
          uVar26 = 0x81;
        }
        else {
          pcVar17 = (code *)0x0;
          uVar26 = 0x81;
        }
        goto LAB_23e791ad5;
      }
      plVar16 = (longlong *)FUN_23e8c09e0(plVar15,plVar14);
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        FUN_23a334bc0(plVar15);
      }
      lVar11 = *plVar14;
      *plVar14 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        FUN_23a334bc0(plVar14);
      }
      if (plVar16 == (longlong *)0x0) {
        pcVar21 = *(code **)(param_1 + 0x70);
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar17 = (code *)0x0;
        uVar26 = 0x81;
        local_f8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e791ad5;
      }
      local_f8 = (longlong *)FUN_23e8c5d90(plVar16,_DAT_23eed8240);
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
      if (local_f8 == (longlong *)0x0) goto LAB_23e793014;
      plVar14 = (longlong *)FUN_23a388650(param_1,plVar12,DAT_23ed6ccf8,1);
      pcVar17 = (code *)0x0;
      if (plVar14 == (longlong *)0x0) {
LAB_23e792f6c:
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar26 = 0x82;
        *(undefined8 *)(param_1 + 0x70) = 0;
        goto LAB_23e791ad5;
      }
      plVar15 = (longlong *)FUN_23e8c09e0(plVar14,local_108);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0(plVar14);
      }
      if (plVar15 == (longlong *)0x0) {
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar17 = (code *)0x0;
        uVar26 = 0x82;
        *(undefined8 *)(param_1 + 0x70) = 0;
        goto LAB_23e791ad5;
      }
      pcVar17 = (code *)FUN_23e8bf9b0(plVar15,_DAT_23eed8240);
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        FUN_23a334bc0(plVar15);
      }
      if (pcVar17 == (code *)0x0) goto LAB_23e792f6c;
      lVar11 = FUN_23e8df6c0();
      if (lVar11 == 0) {
        FUN_23e915740(param_1,&local_78,_DAT_23eed8248);
        uVar26 = 0x85;
        pcVar21 = local_68;
        plVar14 = local_78;
        pcVar24 = pcStack_70;
        goto LAB_23e791ad5;
      }
      *(undefined4 *)(plVar5 + 5) = 0x85;
      local_78 = local_100;
      pcStack_70 = local_f0;
      plVar14 = (longlong *)FUN_23e954670(param_1,lVar11,_DAT_23eed8250,&local_78);
      if (plVar14 == (longlong *)0x0) {
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar26 = 0x85;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar24 = *(code **)(param_1 + 0x68);
        goto LAB_23e791ad5;
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0(plVar14);
      }
      lVar11 = FUN_23e8df810();
      if (lVar11 == 0) {
        FUN_23e915740(param_1,&local_78,_DAT_23eed8258);
        uVar26 = 0x86;
        pcVar21 = local_68;
        plVar14 = local_78;
        pcVar24 = pcStack_70;
        goto LAB_23e791ad5;
      }
      *(undefined4 *)(plVar5 + 5) = 0x86;
      plVar14 = (longlong *)FUN_23e915840(param_1,lVar11,_DAT_23eed8260);
      if (plVar14 == (longlong *)0x0) {
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar26 = 0x86;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar24 = *(code **)(param_1 + 0x68);
        goto LAB_23e791ad5;
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0(plVar14);
      }
      iVar8 = FUN_23e913250(plVar4,_DAT_23eed8270);
      if (iVar8 == -1) {
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar26 = 0x88;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar24 = *(code **)(param_1 + 0x68);
        goto LAB_23e791ad5;
      }
      if (iVar8 == 1) {
        lVar11 = FUN_23e8df6c0();
        if (lVar11 == 0) {
          FUN_23e915740(param_1,&local_78,_DAT_23eed8248);
          uVar26 = 0x89;
          pcVar21 = local_68;
          plVar14 = local_78;
          pcVar24 = pcStack_70;
        }
        else {
          *(undefined4 *)(plVar5 + 5) = 0x89;
          plVar14 = (longlong *)FUN_23e91bfe0(param_1,lVar11,_DAT_23eed8278);
          if (plVar14 != (longlong *)0x0) goto LAB_23e79143e;
          plVar14 = *(longlong **)(param_1 + 0x60);
          pcVar21 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar26 = 0x89;
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar24 = *(code **)(param_1 + 0x68);
        }
        goto LAB_23e791ad5;
      }
      lVar11 = FUN_23e8df6c0();
      if (lVar11 == 0) {
        FUN_23e915740(param_1,&local_78,_DAT_23eed8248);
        uVar26 = 0x8b;
        pcVar21 = local_68;
        plVar14 = local_78;
        pcVar24 = pcStack_70;
        goto LAB_23e791ad5;
      }
      *(undefined4 *)(plVar5 + 5) = 0x8b;
      plVar14 = (longlong *)FUN_23e91bfe0(param_1,lVar11);
      if (plVar14 == (longlong *)0x0) {
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar26 = 0x8b;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar24 = *(code **)(param_1 + 0x68);
        goto LAB_23e791ad5;
      }
LAB_23e79143e:
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0();
      }
      lVar18 = FUN_23e8df810();
      lVar11 = _DAT_23eed8268;
      if (lVar18 == 0) {
        FUN_23e915740(param_1,&local_78,_DAT_23eed8258);
        uVar26 = 0x8d;
        pcVar21 = local_68;
        plVar14 = local_78;
        pcVar24 = pcStack_70;
        goto LAB_23e791ad5;
      }
      *(undefined4 *)(plVar5 + 5) = 0x8d;
      plVar14 = (longlong *)
                FUN_23e915840(param_1,lVar18,_DAT_23eed8260,*(undefined8 *)(lVar11 + 0x18));
      if (plVar14 == (longlong *)0x0) {
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar26 = 0x8d;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar24 = *(code **)(param_1 + 0x68);
        goto LAB_23e791ad5;
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0();
      }
      lVar11 = FUN_23e8df6c0();
      if (lVar11 == 0) {
        FUN_23e915740(param_1,&local_78,_DAT_23eed8248);
        uVar26 = 0x90;
        pcVar21 = local_68;
        plVar14 = local_78;
        pcVar24 = pcStack_70;
        goto LAB_23e791ad5;
      }
      *(undefined4 *)(plVar5 + 5) = 0x90;
      local_78 = local_f8;
      pcStack_70 = pcVar17;
      plVar14 = (longlong *)FUN_23e954670(param_1,lVar11,_DAT_23eed8250,&local_78);
      if (plVar14 == (longlong *)0x0) {
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar26 = 0x90;
        pcVar24 = *(code **)(param_1 + 0x68);
        goto LAB_23e791ad5;
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0(plVar14);
      }
      FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
      pcVar21 = _Py_TrueStruct_exref;
      *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
        goto LAB_23e790985;
      }
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) goto LAB_23e791590;
      goto LAB_23e790994;
    }
    FUN_23e915740(param_1,&local_78,DAT_23eed80c0);
    plVar12 = (longlong *)0x0;
    pcVar21 = local_68;
    plVar14 = local_78;
    pcVar24 = pcStack_70;
LAB_23e792499:
    local_f8 = (longlong *)0x0;
    pcVar17 = (code *)0x0;
    plVar10 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    local_f0 = (code *)0x0;
    uVar26 = 0x75;
    local_100 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
LAB_23e791ad5:
    while( true ) {
      plVar15 = *(longlong **)(param_1 + 0x138);
      local_98._8_8_ = pcVar24;
      local_98._0_8_ = plVar14;
      if (plVar15 != (longlong *)0x0) {
        *plVar15 = *plVar15 + 1;
      }
      pcVar24 = DAT_23ed6a4f8;
      local_88[0] = pcVar21;
      if (pcVar21 == (code *)0x0) {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar24 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar21 = *(code **)DAT_23ed6a4f8;
          *(undefined8 *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar21;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        local_c0 = _PyRuntime_exref;
        *(longlong *)(pcVar24 + 0x10) = 0;
        *(longlong **)(pcVar24 + 0x18) = plVar5;
        *plVar5 = *plVar5 + 1;
        lVar11 = *(longlong *)(local_c0 + 0x1f8);
        *(undefined4 *)(pcVar24 + 0x24) = uVar26;
        lVar11 = *(longlong *)(lVar11 + 0x10);
        *(undefined4 *)(pcVar24 + 0x20) = 0xffffffff;
        lVar11 = *(longlong *)(lVar11 + 0x2e8);
        lVar18 = *(longlong *)(pcVar24 + -8);
        plVar14 = *(longlong **)(lVar11 + 8);
        *plVar14 = (longlong)(pcVar24 + -0x10);
        *(longlong *)(pcVar24 + -0x10) = lVar11;
        *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)plVar14;
        *(code **)(lVar11 + 8) = pcVar24 + -0x10;
        if ((local_88[0] != (code *)0x0) &&
           (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0)
           ) {
          (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))(local_88[0]);
        }
      }
      else {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar24 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar25 = *(code **)DAT_23ed6a4f8;
          *(undefined8 *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar25;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        local_c0 = _PyRuntime_exref;
        *(longlong **)(pcVar24 + 0x18) = plVar5;
        *plVar5 = *plVar5 + 1;
        lVar11 = *(longlong *)(local_c0 + 0x1f8);
        *(undefined4 *)(pcVar24 + 0x24) = uVar26;
        lVar11 = *(longlong *)(lVar11 + 0x10);
        *(undefined4 *)(pcVar24 + 0x20) = 0xffffffff;
        lVar11 = *(longlong *)(lVar11 + 0x2e8);
        lVar18 = *(longlong *)(pcVar24 + -8);
        plVar14 = *(longlong **)(lVar11 + 8);
        *plVar14 = (longlong)(pcVar24 + -0x10);
        *(longlong *)(pcVar24 + -0x10) = lVar11;
        *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)plVar14;
        *(code **)(lVar11 + 8) = pcVar24 + -0x10;
        *(code **)(pcVar24 + 0x10) = pcVar21;
        *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
        if ((local_88[0] != (code *)0x0) &&
           (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0)
           ) {
          (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
        }
      }
      pcVar21 = _Py_NoneStruct_exref;
      local_88[0] = pcVar24;
      if (((code *)local_98._0_8_ != (code *)0x0) &&
         ((code *)local_98._0_8_ != _Py_NoneStruct_exref)) {
        FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
      }
      plVar14 = *(longlong **)(local_98._8_8_ + 0x28);
      if (local_88[0] == pcVar21) {
        pcVar24 = (code *)0x0;
      }
      else {
        pcVar24 = local_88[0];
        if (local_88[0] != (code *)0x0) {
          *(longlong *)local_88[0] = *(longlong *)local_88[0] + 1;
        }
      }
      *(code **)(local_98._8_8_ + 0x28) = pcVar24;
      if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
        (**(code **)(plVar14[1] + 0x30))();
      }
      plVar14 = *(longlong **)(param_1 + 0x138);
      *(undefined8 *)(param_1 + 0x138) = local_98._8_8_;
      if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
        (**(code **)(plVar14[1] + 0x30))();
      }
      *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + -1;
      if (*(longlong *)local_98._0_8_ == 0) {
        (**(code **)(*(longlong *)(local_98._0_8_ + 8) + 0x30))();
      }
      if ((local_88[0] != (code *)0x0) &&
         (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0))
      {
        (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
      }
      local_88[0] = (code *)0x0;
      local_98 = (undefined1  [16])0x0;
      iVar8 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                            *(undefined8 *)PyExc_Exception_exref);
      if (iVar8 == 0) {
        pcVar25 = *(code **)(param_1 + 0x138);
        if ((pcVar25 == pcVar21) || (pcVar25 == (code *)0x0)) {
          local_d0 = *(longlong **)PyExc_RuntimeError_exref;
          pcVar21 = (code *)PyUnicode_FromString("No active exception to reraise");
          pcVar25 = *(code **)(param_1 + 0x138);
          *local_d0 = *local_d0 + 1;
          iVar8 = 0x73;
          *(longlong **)(param_1 + 0x138) = plVar15;
          if ((pcVar25 == (code *)0x0) ||
             (*(longlong *)pcVar25 = *(longlong *)pcVar25 + -1, *(longlong *)pcVar25 != 0))
          goto LAB_23e79205d;
          pcVar24 = (code *)0x0;
          goto LAB_23e7921e0;
        }
        local_d0 = *(longlong **)(pcVar25 + 8);
        pcVar24 = *(code **)(pcVar25 + 0x28);
        *(longlong *)pcVar25 = *(longlong *)pcVar25 + 1;
        *local_d0 = *local_d0 + 1;
        iVar8 = 0;
        pcVar21 = pcVar25;
        if (pcVar24 == (code *)0x0) {
          *(longlong **)(param_1 + 0x138) = plVar15;
          *(longlong *)pcVar25 = *(longlong *)pcVar25 + -1;
          if (*(longlong *)pcVar25 == 0) goto LAB_23e7921e0;
          goto LAB_23e792219;
        }
        *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
        if (*(longlong **)(pcVar24 + 0x18) == plVar5) {
          *(undefined4 *)(plVar5 + 5) = *(undefined4 *)(pcVar24 + 0x24);
        }
        *(longlong **)(param_1 + 0x138) = plVar15;
        *(longlong *)pcVar25 = *(longlong *)pcVar25 + -1;
        if (*(longlong *)pcVar25 != 0) {
          pcVar22 = pcVar24;
          if (plVar5 == *(longlong **)(pcVar24 + 0x18)) goto LAB_23e7916f0;
          goto LAB_23e791ff1;
        }
        (*(code *)local_d0[6])(pcVar25);
        goto LAB_23e791fde;
      }
      plVar14 = *(longlong **)(param_1 + 0x138);
      *plVar14 = *plVar14 + 1;
      uVar19 = FUN_23a3a0d40(DAT_23ed6cf28);
      plVar20 = _DAT_23eed8288;
      lVar11 = *(longlong *)(param_1 + 0x10);
      plVar16 = *(longlong **)(lVar11 + 0xe20);
      if (plVar16 == (longlong *)0x0) {
        plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar18 = plVar16[3];
        *(int *)(lVar11 + 0xebc) = *(int *)(lVar11 + 0xebc) + -1;
        *(longlong *)(lVar11 + 0xe20) = lVar18;
        *plVar16 = 1;
      }
      plVar16[4] = 0;
      lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(local_c0 + 0x1f8) + 0x10) + 0x2e8);
      lVar18 = plVar16[-1];
      puVar6 = *(undefined8 **)(lVar11 + 8);
      *puVar6 = plVar16 + -2;
      plVar16[-2] = lVar11;
      plVar16[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar6;
      *(longlong **)(lVar11 + 8) = plVar16 + -2;
      plVar23 = DAT_23ed6a4c0;
      *plVar20 = *plVar20 + 1;
      plVar16[3] = (longlong)plVar20;
      uVar7 = DAT_23ed6cd28;
      if (plVar23 != (longlong *)0x0) goto LAB_23e791d9b;
      plVar23 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar23 != (longlong *)0x0) break;
      PyErr_PrintEx(0);
      Py_Exit(1);
LAB_23e792a54:
      plVar14 = *(longlong **)(param_1 + 0x60);
      pcVar24 = *(code **)(param_1 + 0x68);
      pcVar21 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      lVar11 = *local_100;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *local_100 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        FUN_23a334bc0(local_100);
      }
LAB_23e7929ae:
      local_f8 = (longlong *)0x0;
      pcVar17 = (code *)0x0;
      uVar26 = 0x79;
      local_f0 = (code *)0x0;
      local_100 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
    }
    *plVar23 = *plVar23 + 1;
    DAT_23ed6a4c0 = plVar23;
LAB_23e791d9b:
    uStack_a0 = uVar7;
    local_a8 = plVar14;
    lVar11 = FUN_23e94ed00(param_1,plVar23,&local_a8);
    if (lVar11 == 0) {
      local_d0 = *(longlong **)(param_1 + 0x60);
      pcVar21 = *(code **)(param_1 + 0x68);
      pcVar24 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
    }
    else {
      plVar16[4] = lVar11;
      plVar20 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
      if (plVar20 != (longlong *)0x0) {
        *(undefined4 *)(plVar5 + 5) = 0x95;
        plVar16 = (longlong *)FUN_23e914090(param_1,uVar19,plVar20);
        *plVar20 = *plVar20 + -1;
        if (*plVar20 == 0) {
          (**(code **)(plVar20[1] + 0x30))(plVar20);
        }
        if (plVar16 != (longlong *)0x0) {
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          pcVar21 = _Py_FalseStruct_exref;
          *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          plVar5 = *(longlong **)(param_1 + 0x138);
          *(longlong **)(param_1 + 0x138) = plVar15;
          if ((plVar5 != (longlong *)0x0) && (*plVar5 = *plVar5 + -1, *plVar5 == 0)) {
            (**(code **)(plVar5[1] + 0x30))();
          }
          goto LAB_23e790921;
        }
      }
      local_d0 = *(longlong **)(param_1 + 0x60);
      pcVar21 = *(code **)(param_1 + 0x68);
      pcVar24 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
    }
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    pcVar25 = *(code **)(param_1 + 0x138);
    *(longlong **)(param_1 + 0x138) = plVar15;
    if (pcVar25 == (code *)0x0) {
      if (pcVar24 != (code *)0x0) {
        plVar14 = *(longlong **)(pcVar24 + 0x18);
joined_r0x00023e79239a:
        pcVar22 = pcVar24;
        pcVar25 = pcVar21;
        if (plVar14 == plVar5) goto LAB_23e7916f0;
        iVar8 = 0x95;
        goto LAB_23e791652;
      }
LAB_23e7929ea:
      iVar8 = 0x95;
      goto LAB_23e79205d;
    }
    *(longlong *)pcVar25 = *(longlong *)pcVar25 + -1;
    if (*(longlong *)pcVar25 != 0) {
      if (pcVar24 == (code *)0x0) goto LAB_23e7929ea;
      plVar14 = *(longlong **)(pcVar24 + 0x18);
      goto joined_r0x00023e79239a;
    }
    iVar8 = 0x95;
LAB_23e7921e0:
    (**(code **)(*(longlong *)(pcVar25 + 8) + 0x30))();
    if (pcVar24 == (code *)0x0) {
      if (iVar8 == 0) {
LAB_23e792219:
        iVar8 = (int)plVar5[5];
      }
      goto LAB_23e79205d;
    }
LAB_23e791fde:
    pcVar22 = pcVar24;
    pcVar25 = pcVar21;
    if (plVar5 == *(longlong **)(pcVar24 + 0x18)) goto LAB_23e7916f0;
    if (iVar8 == 0) {
LAB_23e791ff1:
      iVar8 = (int)plVar5[5];
    }
  }
LAB_23e791652:
  pcVar22 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar22 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar25 = *(code **)DAT_23ed6a4f8;
    *(undefined8 *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar25;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong **)(pcVar22 + 0x18) = plVar5;
  *plVar5 = *plVar5 + 1;
  lVar11 = *(longlong *)(local_c0 + 0x1f8);
  *(int *)(pcVar22 + 0x24) = iVar8;
  *(undefined4 *)(pcVar22 + 0x20) = 0xffffffff;
  lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
  lVar18 = *(longlong *)(pcVar22 + -8);
  plVar14 = *(longlong **)(lVar11 + 8);
  *plVar14 = (longlong)(pcVar22 + -0x10);
  *(longlong *)(pcVar22 + -0x10) = lVar11;
  *(ulonglong *)(pcVar22 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)plVar14;
  lVar18 = *(longlong *)pcVar24;
  *(code **)(lVar11 + 8) = pcVar22 + -0x10;
  *(code **)(pcVar22 + 0x10) = pcVar24;
  pcVar25 = pcVar21;
  if (lVar18 == 0) {
    (**(code **)(*(longlong *)(pcVar24 + 8) + 0x30))(pcVar24);
  }
LAB_23e7916f0:
  FUN_23e8bba40(plVar5,"ooooooooooooo",plVar1,plVar2,plVar3,plVar4,plVar12,plVar10,plVar13,local_108
                ,local_100,local_f0,local_f8,pcVar17,0);
  if (_DAT_23eedac90 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eedac90 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar5 = *(longlong **)(lVar11 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  plVar14 = (longlong *)plVar5[2];
  *(undefined4 *)(plVar5 + 8) = 0xffffffff;
  if (plVar14 != (longlong *)0x0) {
    plVar5[2] = 0;
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))();
    }
  }
  *plVar5 = *plVar5 + -1;
  if (*plVar5 == 0) {
    (**(code **)(plVar5[1] + 0x30))(plVar5);
  }
  plVar5[0xf] = 0;
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((local_108 != (longlong *)0x0) &&
     (lVar11 = *local_108, *local_108 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_108[1] + 0x30))(local_108);
  }
  if ((local_100 != (longlong *)0x0) &&
     (lVar11 = *local_100, *local_100 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_100[1] + 0x30))(local_100);
  }
  if ((local_f0 != (code *)0x0) &&
     (lVar11 = *(longlong *)local_f0, *(longlong *)local_f0 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(*(longlong *)(local_f0 + 8) + 0x30))(local_f0);
  }
  if ((local_f8 != (longlong *)0x0) &&
     (lVar11 = *local_f8, *local_f8 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_f8[1] + 0x30))(local_f8);
  }
  if ((pcVar17 != (code *)0x0) &&
     (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
    (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
  }
  lVar11 = *plVar1;
  *plVar1 = lVar11 + -1;
  if (lVar11 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  lVar11 = *plVar2;
  *plVar2 = lVar11 + -1;
  if (lVar11 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  lVar11 = *plVar3;
  *plVar3 = lVar11 + -1;
  if (lVar11 + -1 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  lVar11 = *plVar4;
  *plVar4 = lVar11 + -1;
  if (lVar11 + -1 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  FUN_23a33aa70(param_1,local_d0,pcVar25,pcVar22);
  return (code *)0x0;
}
